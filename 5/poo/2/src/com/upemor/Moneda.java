package com.upemor;

public class Moneda {
    private double cantidad;

    public Moneda(double cantidad) {
        this.cantidad = cantidad;
    }

    public Moneda() {
        this.cantidad = 1;
    }

    public double getCantidad() {
        return cantidad;
    }

    public void setCantidad(double cantidad) {
        this.cantidad = cantidad;
    }

    public void ADolar() {
        System.out.println(
                getCantidad() * 0.049
        );
    }

    public void AFranco() {
        System.out.println(
                getCantidad() * 0.045
        );
    }

    public void AEuro() {
        System.out.println(
                getCantidad() * 0.043
        );
    }

}
