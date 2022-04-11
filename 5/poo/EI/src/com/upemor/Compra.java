package com.upemor;

import java.io.Serializable;

public class Compra implements Serializable {

    private String Fecha;
    private Auto Auto;

    public Compra(String fecha, Auto auto) {
        Fecha = fecha;
        Auto = auto;
    }

    public String getFecha() {
        return Fecha;
    }

    public com.upemor.Auto getAuto() {
        return Auto;
    }
}
