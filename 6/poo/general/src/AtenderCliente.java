import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.DriverManager;

public class AtenderCliente {
    private ServerSocket s;
    private String ip;
    private int port;

    public AtenderCliente(String ip, int port) throws Exception {
        this.s = new ServerSocket(port, 1, InetAddress.getByName(ip));
        this.ip = ip;
        this.port = port;
    }

    public void Escucha() throws IOException {
        String msj;
        Socket client = this.s.accept();
        String direccion = client.getInetAddress().getHostAddress();

        BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
        while ((msj = in.readLine()) != null) {
            System.out.println(" " + direccion + "  " + port + " dijo: " + msj);
        }
    }

    public static void main(String[] args) throws Exception {
        AtenderCliente a = new AtenderCliente("127.0.0.1", 2206);
        a.Escucha();
    }

    private  Connection conn = null;
    public Connection get(){
        try {
            Class.forName("");
            conn = (Connection) DriverManager.getConnection("", "", "");
        }catch (Exception e) {

        }
        return conn;
    }

}
