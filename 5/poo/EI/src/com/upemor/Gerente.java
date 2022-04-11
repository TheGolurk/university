package com.upemor;

import java.io.Serializable;

public class Gerente extends Empleado implements Serializable {


    public Gerente(String nombre, String rfc, Double salario) {
        super(nombre, rfc, salario);
    }
}
