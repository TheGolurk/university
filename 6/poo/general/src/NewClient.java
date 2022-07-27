import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class NewClient {
    private Socket socket;
    private Scanner sc;

    public NewClient(InetAddress addr, int port) throws IOException {
        this.socket = new Socket(addr, port);
        this.sc = new Scanner(System.in);
    }

    private void start() throws IOException {
        String input;

        while (true) {
            input = this.sc.nextLine();
            PrintWriter pw = new PrintWriter(this.socket.getOutputStream(), true);
            pw.println(input);
            pw.flush();
        }
    }

    public static void main(String[] args) throws IOException {
        NewClient c = new NewClient(InetAddress.getByName("127.0.0.1"), 2206);
        c.start();
    }
}
