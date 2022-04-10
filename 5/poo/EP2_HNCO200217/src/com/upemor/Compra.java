package com.upemor;

public class Compra {
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
