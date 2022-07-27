import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class AtenderClienteHilo extends Thread {
    private ServerSocket s;
    private String dir;

    public AtenderClienteHilo(ServerSocket s, String dir) {
        this.s = s;
        this.dir = dir;
    }

    @Override
    public void run() {
        System.out.println("Se atiende a " + dir);
    }



}
