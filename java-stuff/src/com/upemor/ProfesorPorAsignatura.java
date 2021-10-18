package com.upemor;

public class ProfesorPorAsignatura extends Profesor{
    double precioPorHora;
    int numeroHorasTrabajadas;

    public ProfesorPorAsignatura(double precioPorHora, int numeroHorasTrabajadas) {
        this.precioPorHora = precioPorHora;
        this.numeroHorasTrabajadas = numeroHorasTrabajadas;
    }

    public double getPrecioPorHora() {
        return precioPorHora;
    }

    public void setPrecioPorHora(double precioPorHora) {
        this.precioPorHora = precioPorHora;
    }

    public int getNumeroHorasTrabajadas() {
        return numeroHorasTrabajadas;
    }

    public void setNumeroHorasTrabajadas(int numeroHorasTrabajadas) {
        this.numeroHorasTrabajadas = numeroHorasTrabajadas;
    }

    @Override
    public double sueldo() {
        return 0;
    }
}
