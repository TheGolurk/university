import java.io.Serializable;
import java.util.ArrayList;

public class sucursal implements Serializable {
    private ArrayList<clientes> clientes;

    public sucursal(ArrayList<clientes> clientes) {
        this.clientes = clientes;
    }
}
