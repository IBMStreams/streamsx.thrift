package ThriftSinkCommon;

use strict;
use warnings;

use File::Basename qw(dirname);
use File::Path qw(make_path);

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
	ThriftCommon::createThrift($model, '>>');
}

sub generateOperatorFunctionsCall($) {
	my ($model) = @_;
	my $class = $model->getContext()->getClass();
	
	foreach my $port (@{$model->getInputPorts()}) {
		my $portIndex = $port->getIndex();
		
		my $funcParams = '';
		my $outputAttrs = '';
		foreach my $attr (@{$port->getAttributes()}) {
			my $attrName = $attr->getName();
			my $attrType = $attr->getSPLType();
			(my $attrTypeAlias = $attrType) =~ s/<|,|>/_/g;
			
			if(SPL::CodeGen::Type::isCollection($attrType)) {
				$funcParams = $funcParams . "$attrTypeAlias(ituple.get_$attrName().begin(), ituple.get_$attrName().end()), ";
			}
			else {
				if(SPL::CodeGen::Type::isBlob($attrType)) {
					$funcParams .= "convertFromBlob(ituple.get_$attrName()), ";
				}
				else {
					$funcParams .= "ituple.get_$attrName(), ";
				}
			}
		}
		
		$funcParams =~ s/, $//;
		
		print "\t IPort<$portIndex>::type ituple = static_cast<const IPort<$portIndex>::type &>(tuple); \n";
		print "\n\t\t client_.sendAsync_$portIndex($funcParams); \n";
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
	return ThriftCommon::getTargetDir($model, $thriftOutputDir);
}

1;
