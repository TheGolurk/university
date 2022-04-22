import java.io.Serializable;

public class inmueble implements Serializable {
    private String estado;
    private String municipio;
    private String direccion;
    private int numerohabitaciones;
    private double metroscuadrados;
    private int edadInmueble;
    private int numBanios;

    public inmueble(String estado, String municipio, String direccion, int numerohabitaciones, double metroscuadrados, int edadInmueble, int numBanios) {
        this.estado = estado;
        this.municipio = municipio;
        this.direccion = direccion;
        this.numerohabitaciones = numerohabitaciones;
        this.metroscuadrados = metroscuadrados;
        this.edadInmueble = edadInmueble;
        this.numBanios = numBanios;
    }

    public String getEstado() {
        return estado;
    }

    public String getMunicipio() {
        return municipio;
    }

    public String getDireccion() {
        return direccion;
    }

    public int getNumerohabitaciones() {
        return numerohabitaciones;
    }

    public double getMetroscuadrados() {
        return metroscuadrados;
    }

    public int getEdadInmueble() {
        return edadInmueble;
    }

    public int getNumBanios() {
        return numBanios;
    }
}
