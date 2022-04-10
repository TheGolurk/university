package com.upemor;

import java.io.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class Vendedor extends Empleado implements Serializable{
    private ArrayList<Double> Ventas;

    public Vendedor(String nombre, int edad, double salario) {
        super(nombre, edad, salario);
        Ventas = new ArrayList<Double>();
    }

    public void RegistrarVenta(Double v) {
        Ventas.add(v);
    }

    public ArrayList<Double> getVentas() {
        return Ventas;
    }
}
