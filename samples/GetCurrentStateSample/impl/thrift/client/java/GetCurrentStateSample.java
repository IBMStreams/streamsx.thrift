import com.ibm.streamsx.thrift.*;

import org.apache.thrift.TException;
import org.apache.thrift.transport.TSSLTransportFactory;
import org.apache.thrift.transport.TTransport;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TSSLTransportFactory.TSSLTransportParameters;
import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;

public class GetCurrentStateSample {
  public static void main(String [] args) {

  try {
      TTransport transport;
	  transport = new TSocket("localhost", 5656);
	  transport.open();

      TProtocol protocol = new TBinaryProtocol(transport);
      ThriftSource_1.Client client = new ThriftSource_1.Client(protocol);

      perform(client);

      transport.close();
  } catch (TException x) {
      x.printStackTrace();
  } 
  }

  private static void perform(ThriftSource_1.Client client) throws TException
  {
    client.sendAsync_0(false);
    System.out.println("Request false is sent.");
  }
}
