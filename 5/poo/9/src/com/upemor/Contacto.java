package com.upemor;

public class Contacto {
    private String nombre;
    private String apellido;
    private int edad;

    public Contacto(String nombre, String apellido, int edad) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    @Override
    public int hashCode() {
        return this.nombre.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) return false;
        Contacto c = (Contacto)obj;
        return this.nombre.equals(c.nombre);
    }
}
