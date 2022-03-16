package com.upemor;

import java.util.ArrayList;

public class Usuario {
    private int NumeroRegistro;
    private String Nombre;
    private String direccion;
    private String telefono;
    private ArrayList<Prestamo> LibrosPrestados;


    public boolean SolicitarNuevoLibro(Libro libro) {
        return true;
    }


}
