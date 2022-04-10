package com.upemor;

import java.io.Serializable;
import java.util.ArrayList;

public class Cliente implements Serializable {
    private String Nombre;
    private int Edad;
    private String Correo;
    private ArrayList<Compra> Compras;
    private ArrayList<Servicio> Servicios;

    public Cliente(String nombre, int edad, String correo) {
        Nombre = nombre;
        Edad = edad;
        Correo = correo;
        Compras = new ArrayList<Compra>();
        Servicios = new ArrayList<Servicio>();
    }

    public String getNombre() {
        return Nombre;
    }

    public int getEdad() {
        return Edad;
    }

    public String getCorreo() {
        return Correo;
    }

    public ArrayList<Compra> getCompras() {
        return Compras;
    }

    public ArrayList<Servicio> getServicios() {
        return Servicios;
    }

}