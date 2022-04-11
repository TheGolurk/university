package com.upemor;

import java.io.Serializable;

public class Empleado implements Serializable {

    private String Nombre;
    private String RFC;
    private Double Salario;

    public Empleado(String nombre, String rfc, Double salario){
        Nombre= nombre;
        RFC=rfc;
        Salario=salario;
    }

    public String getNombre() {
        return Nombre;
    }

    public Double getSalario() {
        return Salario;
    }

    public String getRFC() {
        return RFC;
    }

}
