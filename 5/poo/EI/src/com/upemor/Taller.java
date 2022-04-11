package com.upemor;
import java.io.Serializable;
import java.util.ArrayList;

public class Taller implements Serializable {
    private ArrayList<Servicio> Servicios;

    public boolean AgregarServicio(Servicio s) {
        return Servicios.add(s);
    }

    public ArrayList<Servicio> getServicios() {
        return Servicios;
    }

    public Taller() {
        Servicios = new ArrayList<Servicio>();
    }
}
