import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class NewServer {
    private ServerSocket server;

    public NewServer(String ip) throws Exception {
        this.server = new ServerSocket(2206, 1, InetAddress.getByName(ip));
    }

    public void listen() throws Exception{
        String data;
        Socket client = this.server.accept();
        String clientAddr = client.getInetAddress().getHostAddress();

        BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
        while ((data = in.readLine()) != null) {
            new HiloServidor(clientAddr, data).start();
        }

    }

    public static void main(String[] args) throws Exception {
        NewServer s = new NewServer("127.0.0.1");
        s.listen();
    }
}
