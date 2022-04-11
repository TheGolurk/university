package com.upemor;
/*
    INTEGRANTES DEL EQUIPO:
    HERNÁNDEZ NAJERA CHRISTIAN   HNCO200217
    VALLE GONZALEZ LORENA   VGLO200389
 */


import com.upemor.utilities.ClienteUtilidades;
import com.upemor.utilities.EmpleadoUtilidades;
import com.upemor.utilities.SucursalUtilidades;

import java.util.Scanner;

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
        clienteUtilidades.Crear(ArchivoClientes);
        empleadoUtilidades.Crear(ArchivoEmpleados);
        sucursalUtilidades.Crear(ArchivoSucursal);

        Scanner sc = new Scanner(System.in);
        int opc = 0;

        do {
            System.out.println("******************************************************");
            System.out.println("************************ MENU ************************");
            System.out.println("******************************************************");
            System.out.println("************* 1.- REGISTRAR UNA SUCURSAL *************");
            System.out.println("************* 2.-  GESTIONAR UN CLIENTE ***************");
            System.out.println("+* 3.- REGISTRAR UN CLIENTE QUE ACUDA A UNA SUCURSAL *");
            System.out.println("************* 4.- GESTIONAR EMPLEADOS *****************");
            System.out.println("5.- REGISTRAR LA COMPRA DE UN CLIENTE EN UNA SUCURSAL ");
            System.out.println("******* 6.- SOLICITAR UN SERVICIO PARA UN AUTO *******");
            System.out.println("******* 7.- MOSTRAR EL INFORME DE UNA SUCURSAL *******");
            System.out.println("********************* 8.- SALIR **********************");
            System.out.println("******************************************************");
            System.out.println("****** Selecciona la Opcion que Desees (1-8) *********");
            opc = sc.nextInt();

            switch (opc) {
                case 1:
                    sucursalUtilidades.AgregarSucursal(ArchivoSucursal, sucursalUtilidades.ObtenerSucursal());
                    break;

                case 2:

                    int o1 = 0;
                    System.out.println("OPCIONES PARA CLIENTE:");
                    System.out.println("1.-Registrar");
                    System.out.println("2.-Editar");
                    System.out.println("3.-Consultar");
                    System.out.println("4.-Eliminar");
                    System.out.println("Ingresa la opcion a realizar:");
                    o1 = sc.nextInt();
                    switch (o1) {
                        case 1:
                            // registrar
                            clienteUtilidades.AgregarCliente(ArchivoClientes, clienteUtilidades.ObtenerCliente());
                            break;

                        case 2:
                            // editar
                            clienteUtilidades.EditarCliente(ArchivoClientes);
                            break;

                        case 3:
                            // consultar
                            clienteUtilidades.ConsultarClientes(ArchivoClientes);
                            break;

                        case 4:
                            // eliminar
                            clienteUtilidades.EliminarCliente(ArchivoClientes);
                            break;

                        default:
                            System.out.println("Opcion incorrecta");
                            break;
                    }

                    break;

                case 3:
                    sucursalUtilidades.AgregarClienteSucursal(ArchivoClientes, ArchivoSucursal);
                    break;

                case 4:

                    int o2 = 0;
                    System.out.println("OPCIONES PARA EMPLEADO:");
                    System.out.println("1.-Registrar");
                    System.out.println("2.- Editar");
                    System.out.println("3.-Consultar");
                    System.out.println("4.-Eliminar");
                    System.out.println("Ingresa la opcion a realizar:");
                    o2 = sc.nextInt();
                    switch (o2) {
                        case 1:
                            // registrar
                            empleadoUtilidades.AgregarEmpleado(ArchivoEmpleados, empleadoUtilidades.ObtenerEmpleado());
                            break;

                        case 2:
                            // editar
                            empleadoUtilidades.EditarEmpleado(ArchivoEmpleados);
                            break;
                        case 3:
                            // consultar
                            empleadoUtilidades.ConsultarEmpleado(ArchivoEmpleados);
                            break;
                        case 4:
                            // eliminar
                            empleadoUtilidades.EliminarEmpleado(ArchivoEmpleados);
                            break;

                        default:
                            System.out.println("Opcion incorrecta");
                            break;
                    }

                    break;

                case 5:
                    sucursalUtilidades.CompraClienteSucursal(ArchivoSucursal);
                    break;

                case 6:
                    sucursalUtilidades.ServicioAutoSucursal(ArchivoSucursal);
                    break;

                case 7:
                    sucursalUtilidades.ConsultarSucursales(ArchivoSucursal);
                    break;

            }

        } while (opc != 8);

    }


}
