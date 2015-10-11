
package ThriftSource_cpp;
use strict; use Cwd 'realpath';  use File::Basename;  use lib dirname(__FILE__);  use SPL::Operator::Instance::OperatorInstance; use SPL::Operator::Instance::Annotation; use SPL::Operator::Instance::Context; use SPL::Operator::Instance::Expression; use SPL::Operator::Instance::ExpressionTree; use SPL::Operator::Instance::ExpressionTreeEvaluator; use SPL::Operator::Instance::ExpressionTreeVisitor; use SPL::Operator::Instance::ExpressionTreeCppGenVisitor; use SPL::Operator::Instance::InputAttribute; use SPL::Operator::Instance::InputPort; use SPL::Operator::Instance::OutputAttribute; use SPL::Operator::Instance::OutputPort; use SPL::Operator::Instance::Parameter; use SPL::Operator::Instance::StateVariable; use SPL::Operator::Instance::TupleValue; use SPL::Operator::Instance::Window; 
sub main::generate($$) {
   my ($xml, $signature) = @_;  
   print "// $$signature\n";
   my $model = SPL::Operator::Instance::OperatorInstance->new($$xml);
   unshift @INC, dirname ($model->getContext()->getOperatorDirectory()) . "/../impl/nl/include";
   $SPL::CodeGenHelper::verboseMode = $model->getContext()->isVerboseModeOn();
   	my $transport = $model->getParameterByName('port')->getValueAt(0)->getCppExpression();
   	my $class = $model->getContext()->getClass();
   	my $numberOfInputPorts = $model->getNumberOfInputPorts;
   	my $lastInputPort = $numberOfInputPorts - 1;
   print "\n";
   print "\n";
   SPL::CodeGen::implementationPrologue($model);
   print "\n";
   print "\n";
   print 'MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR() : handler_(new ';
   print $class;
   print 'Handler(*this)), processor_(new ';
   print $class;
   print 'Processor(handler_)),', "\n";
   print '							 serverTransport_(new TServerSocket(';
   print $transport;
   print ')), transportFactory_(new TBufferedTransportFactory()),', "\n";
   print '							 protocolFactory_(new TBinaryProtocolFactory()), server_(processor_, serverTransport_, transportFactory_, protocolFactory_) {', "\n";
   print "\n";
   print '	';
   foreach my $portIndex (0..$lastInputPort) {
   print "\n";
   print '		ios_promise_[';
   print $portIndex;
   print '] = shared_ptr<void>(new promise<IPort<';
   print $portIndex;
   print '>::type>());', "\n";
   print '	';
   }
   print "\n";
   print '}', "\n";
   print "\n";
   print 'MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() {}', "\n";
   print "\n";
   print 'void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady() {', "\n";
   print '	createThreads(';
   print $numberOfInputPorts;
   print ' + 1);', "\n";
   print '}', "\n";
   print "\n";
   print 'void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() {', "\n";
   print '	server_.stop();', "\n";
   print "\n";
   print '	';
   foreach my $portIndex (0..$lastInputPort) {
   print "\n";
   print '		ios_[';
   print $portIndex;
   print '].stop();', "\n";
   print '	';
   }
   print "\n";
   print '}', "\n";
   print "\n";
   print 'void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx) {', "\n";
   print '	if (!getPE().getShutdownRequested()) {', "\n";
   print '		if(idx){', "\n";
   print '		  ';
   if($numberOfInputPorts > 0) {
   print "\n";
   print '			const int portIndex = idx-1;', "\n";
   print '			io_service::work work(ios_[portIndex]);', "\n";
   print '			ios_[portIndex].run();', "\n";
   print '		  ';
   }
   print "\n";
   print '		}', "\n";
   print '		else {', "\n";
   print '			server_.serve();', "\n";
   print '		}', "\n";
   print '	}', "\n";
   print '}', "\n";
   print "\n";
   print 'void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) {', "\n";
   print '  ';
   if($numberOfInputPorts > 0) {
   print "\n";
   print '    try {', "\n";
   print '		switch(port) {', "\n";
   print '		';
   foreach my $portIndex (0..$lastInputPort) {
   print "\n";
   print '			case ';
   print $portIndex;
   print ': (*static_pointer_cast<promise<IPort<';
   print $portIndex;
   print '>::type> >(ios_promise_[';
   print $portIndex;
   print '])).set_value(static_cast<const IPort<';
   print $portIndex;
   print '>::type &>(tuple));', "\n";
   print '				break;', "\n";
   print '		';
   }
   print "\n";
   print '		}', "\n";
   print '    }', "\n";
   print '    catch (...) {}', "\n";
   print '  ';
   }
   print "\n";
   print '}', "\n";
   print "\n";
   SPL::CodeGen::implementationEpilogue($model);
   print "\n";
   CORE::exit $SPL::CodeGen::USER_ERROR if ($SPL::CodeGen::sawError);
}
1;
