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

    public Usuario(int numeroRegistro, String nombre, String direccion, String telefono, ArrayList<Prestamo> librosPrestados) {
        NumeroRegistro = numeroRegistro;
        Nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        LibrosPrestados = librosPrestados;
    }
}
