package com.upemor;

import java.util.ArrayList;

public class Vendedor extends Empleado {

    private ArrayList<Compra> Compras;

    public boolean AgregarCompra(Compra c) {
            return Compras.add(c);
    }

    public ArrayList<Compra> getCompras() {
        return Compras;
    }

    public Vendedor(String nombre, String rfc, Double salario) {
        super(nombre, rfc, salario);
    }
}
