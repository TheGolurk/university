package com.upemor;

public class Distancias {
    private double x,y;
    private double []a;
    private double []b;

    public Distancias(double x, double y, double []a, double []b) {
        this.x = x;
        this.y = y;
        this.a = a;
        this.b = b;
    }

    public double[] getA() {
        return a;
    }

    public double[] getB() {
        return b;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double Euclidiana(Distancias d) {
        double dx = getX() - d.getX();
        double dy = getY() - d.getY();

        return Math.sqrt(Math.pow(dx, 2) + Math.pow(dy, 2));
    }

    public int Manhattan() {
        return Math.abs( (int) getX() - (int) getY() );
    }

    public double Minkowski(int q) {
        double sum = 0;
        for (int i = 0; i < a.length ; i++) {
            sum += Math.pow(Math.abs(a[i] - b[i]), q);
        }
        return Math.pow(sum, 1.0 / q);
    }
}
