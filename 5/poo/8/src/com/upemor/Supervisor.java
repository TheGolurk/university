package com.upemor;

import java.util.ArrayList;

public class Supervisor extends Empleado{
    private ArrayList<Restaurador> EmpleadosACargo;

    public Supervisor(String nombre, String RFC, double sueldo, ArrayList<Restaurador> empleadosACargo) {
        super(nombre, RFC, sueldo);
        EmpleadosACargo = empleadosACargo;
    }
}
