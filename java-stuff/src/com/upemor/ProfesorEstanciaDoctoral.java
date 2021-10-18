package com.upemor;

public class ProfesorEstanciaDoctoral extends Profesor {
    double sueldoConacty;

    public ProfesorEstanciaDoctoral(double sueldoConacty) {
        this.sueldoConacty = sueldoConacty;
    }

    public double getSueldoConacty() {
        return sueldoConacty;
    }

    public void setSueldoConacty(double sueldoConacty) {
        this.sueldoConacty = sueldoConacty;
    }

    @Override
    public double sueldo() {
        return 0;
    }
}
