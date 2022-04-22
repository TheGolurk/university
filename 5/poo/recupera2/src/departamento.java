import java.io.Serializable;

public class departamento extends inmueble implements Serializable {
    private int pisodepartamento;
    private boolean tieneelevador;
    private boolean tienelavado;

    public departamento(String estado, String municipio, String direccion, int numerohabitaciones, double metroscuadrados, int edadInmueble, int numBanios, int pisodepartamento, boolean tieneelevador, boolean tienelavado) {
        super(estado, municipio, direccion, numerohabitaciones, metroscuadrados, edadInmueble, numBanios);
        this.pisodepartamento = pisodepartamento;
        this.tieneelevador = tieneelevador;
        this.tienelavado = tienelavado;
    }
}
