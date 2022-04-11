package com.upemor;

import java.util.ArrayList;

public class Sucursal {

    private String Direccion;
    private Gerente Gerente;
    private Taller Taller;
    private ArrayList<Empleado> Empleados;
    private ArrayList<Cliente> Clientes;

    public boolean AgregarCliente(Cliente c) {
        return Clientes.add(c);
    }

    public boolean AgregarEmpleado(Empleado e) {
        return Empleados.add(e);

    }


    public Sucursal(String direccion, Gerente gerente, Taller taller) {
        Direccion=direccion;
        Gerente=gerente;
        Taller = taller;
        Empleados = new ArrayList<Empleado>();
        Clientes = new ArrayList<Cliente>();
    }

    public com.upemor.Taller getTaller() {
        return Taller;
    }

    public ArrayList<Cliente> getClientes() {
        return Clientes;
    }


    public String getDireccion() {
        return Direccion;
    }

    public ArrayList<Empleado> getEmpleados() {
        return Empleados;
    }

}
