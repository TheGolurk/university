package com.upemor;

public class Hombre extends Persona{

    private String genero;

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public Hombre(String genero, String nombre, String apellidos, String RFC, float altura, float peso) {
        super(nombre, apellidos, RFC, altura, peso);
        this.genero = genero;
    }
}
