package com.upemor;

import java.util.Arrays;

public class Materia {
    private String Nombre;
    private double Calificacion;

    public Materia(String nombre, double calificacion) {
        Nombre = nombre;
        Calificacion = calificacion;
    }

    public String getNombre() {
        return Nombre;
    }

    public void setNombre(String nombre) {
        Nombre = nombre;
    }

    public double getCalificacion() {
        return Calificacion;
    }

    public void setCalificacion(double calificacion) {
        Calificacion = calificacion;
    }

}
