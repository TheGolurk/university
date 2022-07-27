import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class SerAtendido {

    private Socket s;
    private Scanner scann;

    public SerAtendido(InetAddress direccion) throws IOException {
        this.s = new Socket(direccion, 2206);
        this.scann = new Scanner(System.in);
    }

    public void MandarMensajes() throws IOException {
        String entrada;
        for (;;) {
            entrada = scann.nextLine();
            PrintWriter pw = new PrintWriter(this.s.getOutputStream(), true);
            pw.println(entrada);
            pw.flush();
        }
    }

    public static void main(String[] args) throws IOException {
        SerAtendido s = new SerAtendido(InetAddress.getByName("127.0.0.1"));
        s.MandarMensajes();
    }
}
