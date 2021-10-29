package com.upemor;

public class Mujer extends Persona {

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    private String genero;

    public Mujer(String genero,String nombre, String apellidos, String RFC, float altura, float peso) {
        super(nombre, apellidos, RFC, altura, peso);
        this.genero = genero;
    }
}
