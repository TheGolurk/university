import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.*;

/**
 *
 * @author joyke
 */
public class cliente {
    public static void main(String args[]) {
        InetAddress direcc = null;
        try {
            {
                direcc = InetAddress.getByName(args[0]);
            }
            System.out.println("Aqui paso");
        } catch (UnknownHostException uhe) {
            System.err.println("Host no encontrado: " + uhe);
            System.exit(-1);
        }
        int puerto = 1234;
        for (int n = 1; n < args.length; n++) {
            Socket sckt = null;
            DataInputStream dls = null;
            DataOutputStream dos = null;
            try {
                int numero = Integer.parseInt(args[n]);
                sckt = new Socket(direcc, puerto);

                dls = new DataInputStream(sckt.getInputStream());
                dos = new DataOutputStream(sckt.getOutputStream());

                dos.writeInt(numero);
                long resultado = dls.readLong();

                System.out.println("Solicitud = " + numero + "\tResultado = " + resultado);

                dls.close();
                dos.close();
            } catch (Exception e) {
                System.err.println("Se ha producido la excepcion: " + e);
            }
            try {
                if (sckt != null) {
                    sckt.close();
                }
            } catch (IOException ioe) {
                System.err.println("Error al cerrar el socket:" + ioe);
            }
        }
    }
}