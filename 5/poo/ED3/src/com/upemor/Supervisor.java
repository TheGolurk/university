package com.upemor;

import java.io.File;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;

public class Supervisor extends Empleado implements Serializable {

    private ArrayList<Vendedor> Vendedores;

    public Supervisor(String nombre, int edad, double salario) {

        super(nombre, edad, salario);
        Vendedores = new ArrayList<Vendedor>();

    }

    public void AgregarVendedor(Vendedor AVendedor){
        Vendedores.add(AVendedor);
    }


}
