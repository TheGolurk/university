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

        Scanner sc =new Scanner(System.in);
        int opc = 0;

        do{
            System.out.println("******************************************************");
            System.out.println("************************ MENU ************************");
            System.out.println("******************************************************");
            System.out.println("************* 1.- REGISTRAR UNA SUCURSAL *************");
            System.out.println("************* 2.-  GESTIONAR UN CLIENTE ***************");
            System.out.println("+* 3.- REGISTRAR UN CLIENTE QUE ACUEDA A UNA SUCURSAL *");
            System.out.println("************* 4.- GESTIONAR EMPLEADOS *****************");
            System.out.println("5.- REGISTRAR LA COMPRA DE UN CLIENTE EN UNA SUCURSAL ");
            System.out.println("******* 6.- SOLICITAR UN SERVICIO PARA UN AUTO *******");
            System.out.println("******* 7.- MOSTRAR EL INFORME DE UNA SUCURSAL *******");
            System.out.println("********************* 9.- SALIR **********************");
            System.out.println("******************************************************");
            System.out.println("Selecciona la Opcion que Desees (1-8)");
            opc=sc.nextInt();

            switch(opc){
                case 1:

                    break;

                case 2:
                    int


                    break;

                case 3:

                    break;

                case 4:

                    System.out.println("Elige el tipo de empleado a registrar: 1.VENDEDOR, 2. TECNICO");
                    var opcionempleado = sc.nextInt();

                    sc.nextLine();
                    System.out.println(" Ingresa direccion");
                    String direccion = sc.nextLine();

                    if(opcionempleado == 1){

                    }

                    if(opcionempleado ==2){

                    }

                    break;

                case 5:

                    break;

                case 6:


                    break;

                case 7:

                    break;

            }

        }while(opc!=9);

    }


}
