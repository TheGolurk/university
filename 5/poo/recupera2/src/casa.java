import java.io.Serializable;

public class casa extends inmueble implements Serializable {
    private int numpisos;
    private boolean tienejardin;

    public casa(String estado, String municipio, String direccion, int numerohabitaciones, double metroscuadrados, int edadInmueble, int numBanios, int numpisos, boolean tienejardin) {
        super(estado, municipio, direccion, numerohabitaciones, metroscuadrados, edadInmueble, numBanios);
        this.numpisos = numpisos;
        this.tienejardin = tienejardin;
    }
}
