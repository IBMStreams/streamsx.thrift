package ThriftCommon;

use strict;
use warnings;

use File::Basename qw(dirname);
use File::Path qw(make_path);

sub verifySchemas($) {
	my ($model) = @_;
	
	my @schemas =   ({type => getSupportedSimpleTypes()},
					 {type => getCollectionOfSimpleTypes('list')},
					 {type => getCollectionOfSimpleTypes('map')},
					 {type => getCollectionOfSimpleTypes('set')});
					 
	foreach my $port (@{$model->getInputPorts()}) {
		SPL::CodeGen::checkMaximalSchema($port, @schemas);
	}
					 
	foreach my $port (@{$model->getOutputPorts()}) {
		SPL::CodeGen::checkMaximalSchema($port, @schemas);
	}
}

sub getSupportedSimpleTypes() {
	return ['blob', 'boolean', 'int8', 'int16', 'int32', 'int64', 'float64', 'rstring'];
}

sub getCollectionOfSimpleTypes($) {
	my ($kind) = @_;
	if($kind ne 'map') {
		my @collection;
		foreach (@{getSupportedSimpleTypes()}) {
		 	push(@collection, "$kind<$_>");
		}
		return \@collection;
	}
	else {
		my @map;
		foreach (@{getSupportedSimpleTypes()}) {
			my $simpleType = $_;
			foreach (@{getSupportedSimpleTypes()}) {
			 	push(@map, "map<$simpleType,$_>");
			}
		}
		return \@map;
	}
}

sub createThrift($) {
	my ($model, $direction) = @_;
	my $class = $model->getContext()->getClass();
	my $namespace = "com.ibm.streamsx.thrift";
	
	my $dir = getTargetDir($model,'.');
	my $thriftFile = "$dir/$class.thrift";
	open(my $fh, '>', $thriftFile) or SPL::CodeGen::exitln("Could not open file '$thriftFile' $!");
	
	print $fh "namespace as3 $namespace \n";
	print $fh "namespace c_glib $namespace \n";
	print $fh "namespace cocoa $namespace \n";
	print $fh "namespace cpp $namespace \n";
	print $fh "namespace csharp $namespace \n";
	print $fh "namespace d $namespace \n";
	print $fh "namespace delphi $namespace \n";
	print $fh "namespace erl $namespace \n";
	print $fh "namespace go $namespace \n";
	print $fh "namespace gv $namespace \n";
	print $fh "namespace hs $namespace \n";
	print $fh "namespace html $namespace \n";
	print $fh "namespace java $namespace \n";
	print $fh "namespace javame $namespace \n";
	print $fh "namespace js $namespace \n";
	print $fh "namespace ocaml $namespace \n";
	print $fh "namespace perl $namespace \n";
	print $fh "namespace php $namespace \n";
	print $fh "namespace py $namespace \n";
	print $fh "namespace rb $namespace \n";
	print $fh "namespace st $namespace \n";
	print $fh "namespace xsd $namespace \n";

	print $fh "\n";
	print $fh "typedef binary blob \n";
	print $fh "typedef bool boolean \n";
	print $fh "typedef byte int8 \n";
	print $fh "typedef i16 int16 \n";
	print $fh "typedef i32 int32 \n";
	print $fh "typedef i64 int64 \n";
	print $fh "typedef double float64 \n";
	print $fh "typedef string rstring \n";
	print $fh "\n";

	my $ports = $direction eq '<<' ? $model->getInputPorts() : $model->getOutputPorts();
	foreach my $port (@{$ports}) {
		my $portIndex = $port->getIndex();
		my $tupleAttrs = '';
		print $fh "struct SendResponse_$portIndex { \n";

		my $attrIndex = 1;
		foreach my $attr (@{$port->getAttributes()}) {
			my $attrName = $attr->getName();
			my $attrType = $attr->getSPLType();
			
			print $fh "\t $attrIndex: required $attrType $attrName; \n";
			$attrIndex++;
		}
		print $fh "} \n\n";
	}
	
	print $fh "service $class { \n";
	
	generateThriftFunctions($model, $fh, $direction);
	
	print $fh "}";
	
	close $fh;
}

sub generateThriftFunctions(@) {
	my ($model, $fh, $direction) = @_;

	my $ports = $direction eq '<<' ? $model->getOutputPorts() : $model->getInputPorts();
	my $numberOfInputPorts = $model->getNumberOfInputPorts();
	my $functions = '';
	foreach my $port (@{$ports}) {
		my $portIndex = $port->getIndex();
		my $funcParams = '';
		my $attrIndex = 1;

		foreach my $attr (@{$port->getAttributes()}) {
			my $attrName = $attr->getName();
			$funcParams .= "$attrIndex:" . $attr->getSPLType() . " $attrName, ";
			$attrIndex++;
		}
		$funcParams =~ s/, $//;
		
		if($direction ne '>>' && $portIndex < $numberOfInputPorts) {
			$functions .= "\n\t SendResponse_$portIndex sendSync_$portIndex($funcParams),";
		}
		if($direction ne '<>') {
			$functions .= "\n\t oneway void sendAsync_$portIndex($funcParams),";
		}
	}
	$functions =~ s/,$//;
	print $fh "$functions \n\n";
}

sub generateTypeDefs(@) {
	my ($model) = @_;
	
	print "\t typedef string blob; \n";
	print "\t typedef bool boolean; \n";
	print "\t typedef int8_t int8; \n";
	print "\t typedef int16_t int16; \n";
	print "\t typedef int32_t int32; \n";
	print "\t typedef int64_t int64; \n";
	print "\t typedef double float64; \n";
	print "\t typedef string rstring; \n";

	my %collectionTypes = ();
	foreach my $port (@{$model->getInputPorts()}, @{$model->getOutputPorts()}) {
		foreach my $attr (@{$port->getAttributes()}) {
			my $attrType = $attr->getSPLType();
			my $attrCollectionType = (split('<',$attrType))[0];
			if(SPL::CodeGen::Type::isCollection($attrType) && !(exists $collectionTypes{$attrType})) {
				$collectionTypes{"$attrType"} = '';
				
				if ($attrCollectionType eq 'list') {
					my $attrElementType = SPL::CodeGen::Type::getElementType($attrType);
					print "\t typedef std::vector<$attrElementType> $attrCollectionType" . "_$attrElementType" . "_; \n";
				}
				elsif ($attrCollectionType eq 'map') {
					my $attrKeyType = SPL::CodeGen::Type::getKeyType($attrType);
					my $attrValueType = SPL::CodeGen::Type::getValueType($attrType);
					print "\t typedef std::map<$attrKeyType,$attrValueType> $attrCollectionType" . "_$attrKeyType" . "_$attrValueType" . "_; \n";
				}
				elsif ($attrCollectionType eq 'set') {
					my $attrElementType = SPL::CodeGen::Type::getElementType($attrType);
					print "\t typedef std::set<$attrElementType> $attrCollectionType" . "_$attrElementType" . "_; \n";
				}
			}
		}
	}
}

sub make($) {
	my ($model) = @_;
	my $thriftOutputDirParam = $model->getParameterByName('thriftOutputDir');
	my $thriftOutputDir = (defined $thriftOutputDirParam)
		? $thriftOutputDirParam->getValueAt(0)->getCppExpression()
		: dirname($model->getContext()->getDataDirectory()) . '/etc';

	my $class = $model->getContext()->getClass();
	my $implDir = getTargetDir($model, $thriftOutputDir);
	my $makeDir = $model->getContext()->getOperatorDirectory() . '/../../impl';
	system("make OP=$makeDir SERVICE=$class THRIFT_OUTPUT_DIR=$thriftOutputDir -f $makeDir/Makefile -C $implDir all > /dev/null");
}
	
sub getTargetDir($) {
	my ($model, $thriftOutputDir) = @_;
	my $class = $model->getContext()->getClass();
	my $outputDir = $model->getContext()->getOutputDirectory();
	
	unless(-e $thriftOutputDir or make_path($thriftOutputDir)) {
		SPL::CodeGen::exitln("Unable to create $thriftOutputDir");
	}
	
	my $dir = "$outputDir/ext/$class";
	unless(-e $dir or make_path($dir)) {
		SPL::CodeGen::exitln("Unable to create $dir");
	}
	
	$dir = "$outputDir/ext/$class/bin";
	unless(-e $dir or make_path($dir)) {
		SPL::CodeGen::exitln("Unable to create $dir");
	}
	
	$dir = "$outputDir/ext/$class/include";
	unless(-e $dir or make_path($dir)) {
		SPL::CodeGen::exitln("Unable to create $dir");
	}
	
	$dir = "$outputDir/ext/$class/src";
	unless(-e $dir or make_path($dir)) {
		SPL::CodeGen::exitln("Unable to create $dir");
	}
	
	$dir = "$outputDir/ext/lib";
	unless(-e $dir or make_path($dir)) {
		SPL::CodeGen::exitln("Unable to create $dir");
	}
	
	return "$outputDir/ext/$class";
}

1;
