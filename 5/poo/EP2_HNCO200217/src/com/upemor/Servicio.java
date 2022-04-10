package com.upemor;

public class Servicio {
    private String Nombre;
    private String Descripcion;
    private double Costo;
    private Auto Auto;

    public Servicio(String nombre, String descripcion, double costo, Auto auto){
        Nombre=nombre;
        Descripcion=descripcion;
        Costo=costo;
        Auto=auto;
    }

    public String getNombre() {
        return Nombre;
    }

    public String getDescripcion() {
        return Descripcion;
    }

    public double getCosto() {
        return Costo;
    }

    public com.upemor.Auto getAuto() {
        return Auto;
    }
}
