package com.upemor;

import java.util.ArrayList;

public class Usuario {
    private int NumeroRegistro;
    private String Nombre;
    private String Direccion;
    private String Telefono;
    private ArrayList<Prestamo> LibrosPrestados;

    public boolean SolicitarNuevoLibro(Libro libro) {
        return true;
    }

    public Usuario(int numeroRegistro, String nombre, String direccion, String telefono) {
        NumeroRegistro = numeroRegistro;
        Nombre = nombre;
        Direccion = direccion;
        Telefono = telefono;
    }
}
