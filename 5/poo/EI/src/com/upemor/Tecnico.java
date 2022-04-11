package com.upemor;

import java.util.ArrayList;

public class Tecnico extends Empleado{

    private ArrayList<Servicio> Servicios;

    public Tecnico( String nombre, String rfc, Double salario) {
        super(nombre,rfc,salario);
        Servicios = new ArrayList<Servicio>();
    }

}
