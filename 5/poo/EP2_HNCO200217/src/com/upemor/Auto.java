package com.upemor;

public class Auto {
    private String Modelo;
    private double Costo;

    public Auto(String modelo, double costo) {
        Modelo = modelo;
        Costo = costo;
    }

    public String getModelo() {
        return Modelo;
    }

    public double getCosto() {
        return Costo;
    }
}
