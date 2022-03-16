package com.upemor;

import java.util.ArrayList;

public class Restaurador extends Empleado {
    private ArrayList<Libro> LibrosARestaurar;

    public Restaurador(String nombre, String RFC, double sueldo) {
        super(nombre, RFC, sueldo);
    }
}
