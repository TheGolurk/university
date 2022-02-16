package com.upemor;

public class Triangulo {
    protected double Area;
    private double Altura;
    private double Base;

    public double getArea() {
        return Area;
    }

    public Triangulo(double area, double altura, double base) {
        Area = area;
        Altura = altura;
        Base = base;
    }

    public void ImprimirArea() {
        System.out.println("El area es: " + Area);
    }

    public void CalcularArea() {
        Area = (Base * Altura) / 2;
    }

}
