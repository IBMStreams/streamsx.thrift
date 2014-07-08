
package ThriftSource_h;
use strict; use Cwd 'realpath';  use File::Basename;  use lib dirname(__FILE__);  use SPL::Operator::Instance::OperatorInstance; use SPL::Operator::Instance::Context; use SPL::Operator::Instance::Expression; use SPL::Operator::Instance::ExpressionTree; use SPL::Operator::Instance::ExpressionTreeVisitor; use SPL::Operator::Instance::ExpressionTreeCppGenVisitor; use SPL::Operator::Instance::InputAttribute; use SPL::Operator::Instance::InputPort; use SPL::Operator::Instance::OutputAttribute; use SPL::Operator::Instance::OutputPort; use SPL::Operator::Instance::Parameter; use SPL::Operator::Instance::StateVariable; use SPL::Operator::Instance::Window; 
sub main::generate($$) {
   my ($xml, $signature) = @_;  
   print "// $$signature\n";
   my $model = SPL::Operator::Instance::OperatorInstance->new($$xml);
   unshift @INC, dirname ($model->getContext()->getOperatorDirectory()) . "/../impl/nl/include";
   $SPL::CodeGenHelper::verboseMode = $model->getContext()->isVerboseModeOn();
   	use ThriftSourceCommon;
   
   	ThriftSourceCommon::verifyPorts($model);
   	ThriftSourceCommon::verifySchemas($model);
   	ThriftSourceCommon::createThrift($model);
   	ThriftSourceCommon::make($model);
   
   	my $class = $model->getContext()->getClass();
   	my $numberOfInputPorts = $model->getNumberOfInputPorts;
   	my $lastInputPort = $numberOfInputPorts-1;
   
       my @includes;
       push @includes, "#include <iostream>";
       push @includes, "#include <streams_boost/asio.hpp>";
       push @includes, "#include <streams_boost/bind.hpp>";
       push @includes, "#include <streams_boost/date_time.hpp>";
       push @includes, "#include <streams_boost/ref.hpp>";
       push @includes, "#include <streams_boost/shared_ptr.hpp>";
       push @includes, "#include <streams_boost/static_assert.hpp>";
       push @includes, "#include <streams_boost/thread.hpp>";
       push @includes, "#include \"$class/include/$class.h\"";
       push @includes, "#include <thrift/protocol/TBinaryProtocol.h>";
       push @includes, "#include <thrift/server/TThreadedServer.h>";
       push @includes, "#include <thrift/transport/TServerSocket.h>";
       push @includes, "#include <thrift/transport/TBufferTransports.h>";
       push @includes, "#include <SPL/Runtime/Function/StringFunctions.h>";
   print "\n";
   print "\n";
   SPL::CodeGen::headerPrologue($model, \@includes);
   print "\n";
   print "\n";
   print 'namespace boost = streams_boost;', "\n";
   print "\n";
   print 'using namespace ::apache::thrift;', "\n";
   print 'using namespace ::apache::thrift::protocol;', "\n";
   print 'using namespace ::apache::thrift::transport;', "\n";
   print 'using namespace ::apache::thrift::server;', "\n";
   print "\n";
   print 'using namespace ::com::ibm::streamsx::thrift;', "\n";
   print "\n";
   print 'using namespace SPL::Functions::String;', "\n";
   print "\n";
   print 'using std::string;', "\n";
   print 'using streams_boost::shared_ptr;', "\n";
   print 'using streams_boost::static_pointer_cast;', "\n";
   print 'using streams_boost::asio::io_service;', "\n";
   print 'using streams_boost::bind;', "\n";
   print 'using streams_boost::posix_time::millisec;', "\n";
   print 'using streams_boost::ref;', "\n";
   print 'using streams_boost::promise;', "\n";
   print 'using streams_boost::unique_future;', "\n";
   print "\n";
   print 'class ';
   print $class;
   print 'Handler;', "\n";
   print "\n";
   print 'class MY_OPERATOR : public MY_BASE_OPERATOR {', "\n";
   print '	friend class ';
   print $class;
   print 'Handler;', "\n";
   print 'public:', "\n";
   print '  MY_OPERATOR();', "\n";
   print '  virtual ~MY_OPERATOR(); ', "\n";
   print "\n";
   print '  void allPortsReady(); ', "\n";
   print '  void prepareToShutdown();', "\n";
   print "\n";
   print '  void process(uint32_t idx);', "\n";
   print '  void process(Tuple const & tuple, uint32_t port);', "\n";
   print "\n";
   print 'private:', "\n";
   print '  shared_ptr<';
   print $class;
   print 'Handler> handler_;', "\n";
   print '  shared_ptr<TProcessor> processor_;', "\n";
   print '  shared_ptr<TServerTransport> serverTransport_;', "\n";
   print '  shared_ptr<TTransportFactory> transportFactory_;', "\n";
   print '  shared_ptr<TProtocolFactory> protocolFactory_;', "\n";
   print '  TThreadedServer server_;', "\n";
   print "\n";
   if($numberOfInputPorts > 0) {
   print "\n";
   print '  template <int N>', "\n";
   print '  struct IPort{', "\n";
   print '  	typedef void type;;', "\n";
   print '  };', "\n";
   print "\n";
   print '  io_service ios_[';
   print $numberOfInputPorts;
   print '];', "\n";
   print '  shared_ptr<void> ios_promise_[';
   print $numberOfInputPorts;
   print '];', "\n";
   }
   print "\n";
   print "\n";
   print '};', "\n";
   print "\n";
   if($numberOfInputPorts > 0) {
   print "\n";
   print "\n";
   foreach my $portIndex (0..$lastInputPort) {
   print "\n";
   print '  template <>', "\n";
   print '  struct MY_OPERATOR_SCOPE::MY_OPERATOR::IPort<';
   print $portIndex;
   print '>{', "\n";
   print '	typedef MY_OPERATOR_SCOPE::MY_OPERATOR::IPort';
   print $portIndex;
   print 'Type type;', "\n";
   print '  };', "\n";
   print "\n";
   }
   }
   print "\n";
   print "\n";
   print 'class ';
   print $class;
   print 'Handler : virtual public ';
   print $class;
   print 'If {', "\n";
    ThriftSourceCommon::generateTypeDefs($model); 
   print "\n";
   print "\n";
   print ' public:', "\n";
   print '	';
   print $class;
   print 'Handler(MY_OPERATOR & op) : op_(op) {}', "\n";
   print "\n";
   print '	';
    ThriftSourceCommon::generateOperatorFunctions($model); 
   print "\n";
   print "\n";
   print ' private:', "\n";
   print '	MY_OPERATOR & op_;', "\n";
   print "\n";
   print '	';
    ThriftSourceCommon::generateSubmitFunctions($model); 
   print "\n";
   print '};', "\n";
   print "\n";
   SPL::CodeGen::headerEpilogue($model);
   print "\n";
   CORE::exit $SPL::CodeGen::USER_ERROR if ($SPL::CodeGen::sawError);
}
1;
