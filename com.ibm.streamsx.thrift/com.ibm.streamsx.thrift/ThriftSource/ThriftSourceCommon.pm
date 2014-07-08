package ThriftSourceCommon;

use strict;
use warnings;

use File::Basename qw(dirname);
use File::Path qw(make_path);

sub verifyPorts($) {
	my ($model) = @_;
	
	if($model->getNumberOfInputPorts() > $model->getNumberOfOutputPorts()) {
		SPL::CodeGen::exitln("Number of input ports must be less or equal to number of output ports.");
	}
}

sub verifySchemas($) {
	my ($model) = @_;
	unshift @INC, dirname($model->getContext()->getOperatorDirectory()) . '/Common';
	require ThriftCommon;
	ThriftCommon::verifySchemas($model);
}

sub createThrift($) {
	my ($model) = @_;
	unshift @INC, dirname($model->getContext()->getOperatorDirectory()) . '/Common';
	require ThriftCommon;
	ThriftCommon::createThrift($model, '<<');
}

sub generateOperatorFunctions($) {
	my ($model) = @_;
	my $class = $model->getContext()->getClass();
	
	my $numberOfInputPorts = $model->getNumberOfInputPorts();
	foreach my $port (@{$model->getOutputPorts()}) {
		my $portIndex = $port->getIndex();
		
		my $funcParams = '';
		my $outputAttrs = '';
		my $returnAttrs = '';
		foreach my $attr (@{$port->getAttributes()}) {
			my $attrName = $attr->getName();
			my $attrType = $attr->getSPLType();
			my $attrCppType = $attr->getCppType();
			my $attrRef = SPL::CodeGen::Type::isBlob($attrType) || SPL::CodeGen::Type::isRString($attrType) || SPL::CodeGen::Type::isCollection($attrType) ? '&' : '';
			
			(my $attrTypeAlias = $attrType) =~ s/<|,|>/_/g;
			$attrTypeAlias =~ s/blob/rstring/g;
			$funcParams .= "const $attrTypeAlias $attrRef $attrName, ";
			
			if(SPL::CodeGen::Type::isCollection($attrType)) {
				$outputAttrs .= "\t\t otuple.set_$attrName($attrCppType($attrName.begin(), $attrName.end())); \n";
			}
			else {
				if(SPL::CodeGen::Type::isBlob($attrType)) {
					$outputAttrs .= "\t\t otuple.set_$attrName(convertToBlob($attrName)); \n";
				}
				else {
					$outputAttrs .= "\t\t otuple.set_$attrName($attrName); \n";
				}
			}
		}
		if($portIndex < $numberOfInputPorts) {
			foreach my $attr (@{$model->getInputPortAt($portIndex)->getAttributes()}) {
				my $attrName = $attr->getName();
				my $attrType = $attr->getSPLType();
				my $attrCppType = $attr->getCppType();
				(my $attrTypeAlias = $attrType) =~ s/<|,|>/_/g;
				
				if(SPL::CodeGen::Type::isCollection($attrType)) {
					$returnAttrs .= "\t\t const $attrCppType & _$attrName = rtuple.get_$attrName(); \n";
					$returnAttrs .= "\t\t _return.$attrName = $attrTypeAlias(_$attrName.begin(), _$attrName.end()); \n";
				}
				else {
					if(SPL::CodeGen::Type::isBlob($attrType)) {
						$returnAttrs = $returnAttrs . "\t\t _return.$attrName = convertFromBlob(rtuple.get_$attrName()); \n";
					}
					else {
						$returnAttrs = $returnAttrs . "\t\t _return.$attrName = rtuple.get_$attrName(); \n";
					}
				}
			}
		}
		
		$funcParams =~ s/, $//;
		
		if($portIndex < $numberOfInputPorts) {
			print "\n\t void sendSync_$portIndex(SendResponse_$portIndex & _return, $funcParams) { \n";
			print "\t\t MY_OPERATOR::OPort$portIndex" . "Type otuple; \n";
			print $outputAttrs;
			
			print "\t\t promise<MY_OPERATOR::IPort<$portIndex>::type> p; \n";
			print "\t\t unique_future<MY_OPERATOR::IPort<$portIndex>::type> f(p.get_future()); \n";
			print "\t\t op_.ios_[$portIndex].post(bind(&$class" . "Handler::submitTupleWithResponse_$portIndex, this, otuple, ref(p))); \n";
			print "\t\t const MY_OPERATOR::IPort<$portIndex>::type & rtuple = f.get(); \n";

			print $returnAttrs;
			print "\t } \n";
		}
		
		print "\n\t void sendAsync_$portIndex($funcParams) { \n";
		print "\t\t MY_OPERATOR::OPort$portIndex" . "Type otuple; \n";
		print $outputAttrs;
		print "\t\t op_.submit(otuple, $portIndex); \n";
		print "\t } \n";
		
	}
}

sub generateSubmitFunctions($) {
	my ($model) = @_;
	
	foreach my $port (@{$model->getInputPorts()}) {
		my $portIndex = $port->getIndex();
		
		print "void submitTupleWithResponse_$portIndex(MY_OPERATOR::OPort$portIndex" . "Type & otuple, promise<MY_OPERATOR::IPort<$portIndex>::type> & p) { \n";
		print "\t\t unique_future<MY_OPERATOR::IPort<$portIndex>::type> f = (*static_pointer_cast<promise<MY_OPERATOR::IPort<$portIndex>::type> >(op_.ios_promise_[$portIndex])).get_future(); \n";
		print "\t\t op_.submit(otuple, $portIndex); \n";
		print "\t\t if(f.timed_wait(millisec(1000))) { \n";
		print "\t\t\t p.set_value(f.get()); \n";
		print "\t\t } \n";
		print "\t\t else { \n";
		print "\t\t\t p.set_value(MY_OPERATOR::IPort<$portIndex>::type()); \n";
		print "\t\t } \n";
		print "\t\t op_.ios_promise_[$portIndex] = shared_ptr<void>(new promise<MY_OPERATOR::IPort<$portIndex>::type>()); \n";
		print "\t } \n";
	}
}

sub generateTypeDefs(@) {
	my ($model) = @_;
	unshift @INC, dirname($model->getContext()->getOperatorDirectory()) . '/Common';
	require ThriftCommon;
	ThriftCommon::generateTypeDefs($model);
}

sub make($) {
	my ($model, $thriftOutputDir) = @_;
	unshift @INC, dirname($model->getContext()->getOperatorDirectory()) . '/Common';
	require ThriftCommon;
	ThriftCommon::make($model);
}
	
sub getTargetDir($) {
	my ($model) = @_;
	unshift @INC, dirname($model->getContext()->getOperatorDirectory()) . '/Common';
	require ThriftCommon;
	return ThriftCommon::getTargetDir($model);
}

1;
