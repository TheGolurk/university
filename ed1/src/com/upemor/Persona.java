package com.upemor;

public class Persona implements SerVivo
{
    private String nombre;
    private String apellidos;
    private String RFC;
    private float altura;
    private float peso;


    public Persona(String nombre, String apellidos, String RFC, float altura, float peso) {
        this.nombre = nombre;
        this.apellidos = apellidos;
        this.RFC = RFC;
        this.altura = altura;
        this.peso = peso;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellidos() {
        return apellidos;
    }

    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    public String getRFC() {
        return RFC;
    }

    public void setRFC(String RFC) {
        this.RFC = RFC;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public float Andar()
    {
        peso--;
        System.out.println("Caminando...");
        return peso;
    }

    public float Comer()
    {
        peso++;
        System.out.println("Comiendo...");
        return peso;
    }

    @Override
    public void Nacer() {
        System.out.println("He nacido");
    }

    public void Crecer()
    {
        altura++;
        System.out.println("Creciendo...");
    }

    @Override
    public void Reproducirse() {
        System.out.println("Me he reproducido");
    }

    @Override
    public void Morir() {
        System.out.println("He muerto");
    }
}