package com.upemor;

public class Empleado {
    private String Nombre;
    private String RFC;
    private double Sueldo;

    public Empleado(String nombre, String RFC, double sueldo) {
        Nombre = nombre;
        this.RFC = RFC;
        Sueldo = sueldo;
    }

    public String getNombre() {
        return Nombre;
    }

    public String getRFC() {
        return RFC;
    }

    public double getSueldo() {
        return Sueldo;
    }
}
