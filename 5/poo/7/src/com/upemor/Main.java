package com.upemor;

public class Main {

    public static void main(String[] args) {
        Triangulo t = new Triangulo(10, 14, 2);
        t.CalcularArea();
        t.ImprimirArea();


        TrianguloEquilatero t2 = new TrianguloEquilatero(4, 44, 15);
        t2.CalcularArea();
        t2.ImprimirArea();

        TrianguloIsosceles t3 = new TrianguloIsosceles(16,42,45);
        t2.CalcularArea();
        t2.ImprimirArea();
    }
}
