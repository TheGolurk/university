package com.upemor;
/*
    INTEGRANTES DEL EQUIPO:
    HERNÁNDEZ NAJERA CHRISTIAN   HNCO200217
    VALLE GONZALEZ LORENA   VGLO200389
 */


import com.upemor.utilities.ClienteUtilidades;
import com.upemor.utilities.EmpleadoUtilidades;
import com.upemor.utilities.SucursalUtilidades;

public class Main {

    // File Names
    private static String ArchivoClientes = "Clientes.dat";
    private static String ArchivoEmpleados = "Empleados.dat";
    private static String ArchivoSucursal = "Sucursal.dat";

    // Utilities
    private static final ClienteUtilidades clienteUtilidades = new ClienteUtilidades();
    private static final EmpleadoUtilidades empleadoUtilidades = new EmpleadoUtilidades();
    private static final SucursalUtilidades sucursalUtilidades = new SucursalUtilidades();

    public static void main(String[] args) {

        new ClienteUtilidades().Crear(ArchivoClientes);

        clienteUtilidades.Crear(ArchivoClientes);

        clienteUtilidades.AgregarCliente( ArchivoClientes, new Cliente("Rodolfo", 10, "asd"));


        clienteUtilidades.ConsultarClientes(ArchivoClientes);

    }

}
