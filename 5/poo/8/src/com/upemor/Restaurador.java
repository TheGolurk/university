package com.upemor;

import java.util.ArrayList;

public class Restaurador extends Prestamo {
    public Restaurador(ArrayList<com.upemor.Libro> librosARestaurar) {
        LibrosARestaurar = librosARestaurar;
    }

    private ArrayList<Libro> LibrosARestaurar;
}
