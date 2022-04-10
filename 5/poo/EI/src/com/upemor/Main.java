package com.upemor;

public class Main {

    private static String ArchivoClientes = "Clientes.dat";
    private static String ArchivoEmpleados = "Empleados.dat";

    public static void main(String[] args) {

        new Utilidades().Crear(ArchivoClientes);

        new Utilidades().
                AgregarCliente(
                        ArchivoClientes,
                        new Cliente("Rodolfo", 10, "asd")
                        );

        new Utilidades().
                AgregarCliente(
                        ArchivoClientes,
                        new Cliente("Rodolfo 2", 10, "asd")
                );

        new Utilidades().
                AgregarCliente(
                        ArchivoClientes,
                        new Cliente("Rodolfo 3", 10, "asd")
                );


        new Utilidades().ConsultarClientes(ArchivoClientes);

    }

}
