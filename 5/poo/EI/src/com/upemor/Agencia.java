package com.upemor;

import java.io.Serializable;
import java.util.ArrayList;

public class Agencia implements Serializable {
    private ArrayList<Sucursal> Sucursales;

    public Agencia() {
        Sucursales = new ArrayList<Sucursal>();
    }

    public boolean AgregarSucursal(Sucursal s) {
        return Sucursales.add(s);
    }

    public ArrayList<Sucursal> getSucursales() {
        return Sucursales;
    }

}
