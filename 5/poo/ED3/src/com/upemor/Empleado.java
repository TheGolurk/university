package com.upemor;

public class Empleado {
    private String Nombre;
    private int Edad;
    private double Salario;

    public Empleado(String nombre, int edad, double salario) {
        Nombre = nombre;
        Edad = edad;
        Salario = salario;
    }

    public String getNombre() {
        return Nombre;
    }

    public void setNombre(String nombre) {
        Nombre = nombre;
    }

    public int getEdad() {
        return Edad;
    }

    public void setEdad(int edad) {
        Edad = edad;
    }

    public double getSalario() {
        return Salario;
    }

    public void setSalario(double salario) {
        Salario = salario;
    }
}
