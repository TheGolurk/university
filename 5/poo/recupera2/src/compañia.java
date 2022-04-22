import java.io.Serializable;

public class compañia implements Serializable {
    private sucursal sucursal;

    public compañia(sucursal sucursal) {
        this.sucursal = sucursal;
    }
}
