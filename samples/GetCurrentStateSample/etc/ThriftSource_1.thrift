namespace as3 com.ibm.streamsx.thrift 
namespace c_glib com.ibm.streamsx.thrift 
namespace cocoa com.ibm.streamsx.thrift 
namespace cpp com.ibm.streamsx.thrift 
namespace csharp com.ibm.streamsx.thrift 
namespace d com.ibm.streamsx.thrift 
namespace delphi com.ibm.streamsx.thrift 
namespace erl com.ibm.streamsx.thrift 
namespace go com.ibm.streamsx.thrift 
namespace gv com.ibm.streamsx.thrift 
namespace hs com.ibm.streamsx.thrift 
namespace html com.ibm.streamsx.thrift 
namespace java com.ibm.streamsx.thrift 
namespace javame com.ibm.streamsx.thrift 
namespace js com.ibm.streamsx.thrift 
namespace ocaml com.ibm.streamsx.thrift 
namespace perl com.ibm.streamsx.thrift 
namespace php com.ibm.streamsx.thrift 
namespace py com.ibm.streamsx.thrift 
namespace rb com.ibm.streamsx.thrift 
namespace st com.ibm.streamsx.thrift 
namespace xsd com.ibm.streamsx.thrift 

typedef binary blob 
typedef bool boolean 
typedef byte int8 
typedef i16 int16 
typedef i32 int32 
typedef i64 int64 
typedef double float64 
typedef string rstring 

struct SendResponse_0 { 
	 1: required map<int32,rstring> result; 
} 

service ThriftSource_1 { 

	 SendResponse_0 sendSync_0(1:boolean request),
	 oneway void sendAsync_0(1:boolean request) 

}