package com.upemor;

import java.util.ArrayList;

public class Supervisor extends Empleado{
    private ArrayList<Restaurador> EmpleadosACargo;

    public boolean AgregarEmpleadoAcargo(Restaurador restaurador) {
        return EmpleadosACargo.add(restaurador);
    }

    public Supervisor(String nombre, String RFC, double sueldo) {
        super(nombre, RFC, sueldo);
    }
}
