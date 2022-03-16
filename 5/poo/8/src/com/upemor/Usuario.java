package com.upemor;

import java.util.ArrayList;

public class Usuario {
    private int NumeroRegistro;
    private String Nombre;
    private String Direccion;
    private String Telefono;
    private ArrayList<Prestamo> LibrosPrestados;

    public boolean SolicitarNuevoLibro(Prestamo prestamo) {
        return LibrosPrestados.add(prestamo);
    }

    public Usuario(int numeroRegistro, String nombre, String direccion, String telefono) {
        NumeroRegistro = numeroRegistro;
        Nombre = nombre;
        Direccion = direccion;
        Telefono = telefono;
    }

    public int getNumeroRegistro() {
        return NumeroRegistro;
    }

    public String getNombre() {
        return Nombre;
    }

    public String getDireccion() {
        return Direccion;
    }

    public String getTelefono() {
        return Telefono;
    }

    public ArrayList<Prestamo> getLibrosPrestados() {
        return LibrosPrestados;
    }
}
