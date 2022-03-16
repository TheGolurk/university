package com.upemor;

import java.util.ArrayList;

public class Biblioteca {
    private ArrayList<Usuario> Usuarios;
    private ArrayList<Libro> Libros;
    private ArrayList<Empleado> Empleados;

    public Biblioteca() {
        Usuarios = new ArrayList<Usuario>();
        Libros = new ArrayList<Libro>();
        Empleados = new ArrayList<Empleado>();
    }

    public boolean RegistrarUsuario(Usuario usuario) {
        return Usuarios.add(usuario);
    }

    public boolean RegistrarLibro(Libro libro) {
        return Libros.add(libro);
    }


    public boolean RegistrarEmpleado(Empleado empleado) {
        return Empleados.add(empleado);
    }

    public ArrayList<Usuario> getUsuarios() {
        return Usuarios;
    }

    public ArrayList<Libro> getLibros() {
        return Libros;
    }

    public ArrayList<Empleado> getEmpleados() {
        return Empleados;
    }
}
