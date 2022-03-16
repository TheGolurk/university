package com.upemor;

import java.util.ArrayList;

public class Restaurador extends Empleado {
    private ArrayList<Libro> LibrosARestaurar;

    public boolean AgregarLibroARestaurar(Libro libro) {
        return LibrosARestaurar.add(libro);
    }

    public Restaurador(String nombre, String RFC, double sueldo) {
        super(nombre, RFC, sueldo);
    }
}
