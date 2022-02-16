package com.upemor;

public class TrianguloEquilatero extends Triangulo {

    public TrianguloEquilatero(double area, double altura, double base) {
        super(area, altura, base);
    }

    @Override
    public void CalcularArea() {
        super.CalcularArea();
        Area = (Math.sqrt(3) / 4) * Math.pow(getArea(), 2);
    }

    @Override
    public void ImprimirArea() {
        super.ImprimirArea();
    }
}
