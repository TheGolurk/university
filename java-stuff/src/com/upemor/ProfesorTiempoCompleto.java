package com.upemor;

public class ProfesorTiempoCompleto extends Profesor{
     double salarioSemanal;

    public double getSalarioSemanal() {
        return salarioSemanal;
    }

    public void setSalarioSemanal(double salarioSemanal) {
        this.salarioSemanal = salarioSemanal;
    }

    public ProfesorTiempoCompleto(double salarioSemanal) {
        this.salarioSemanal = salarioSemanal;
    }

    @Override
    public double sueldo() {
        return 0;
    }
}
