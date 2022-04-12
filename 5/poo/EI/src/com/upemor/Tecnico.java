package com.upemor;

import java.io.Serializable;
import java.util.ArrayList;

public class Tecnico extends Empleado implements Serializable {

    private ArrayList<Servicio> Servicios;

    public boolean AgregarServicio(Servicio s) {
        return Servicios.add(s);
    }

    public Tecnico( String nombre, String rfc, Double salario) {
        super(nombre,rfc,salario);
        Servicios = new ArrayList<Servicio>();
    }

}
