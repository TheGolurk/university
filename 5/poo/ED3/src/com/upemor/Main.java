package com.upemor;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/*
    Alumnos:
    HERNANDEZ NÁJERA CHRISTIAN  HNCO200217
    SILVA GONZÁLEZ MOISÉS  SGMO201792
    VALLE GONZÁLEZ LORENA  VGLO200389
*/

public class Main {

    private static ArrayList<Vendedor> vendedores = new ArrayList<Vendedor>();

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int opc = 0;
        do {

            System.out.println("1.- REGISTRAR VENDEDOR ");
            System.out.println("2.- REGISTRAR SUPERVISOR");
            System.out.println("3.- REGISTRAR VENTAS PARA UN VENDEDOR  ");
            System.out.println("4.- REGISTRAR VENDEDORES PARA UN SUPERVISOR");
            System.out.println("5.- MOSTRAR VENTAS DE VENDEDORES");
            System.out.println("6.- SALIR");

            opc = sc.nextInt();
            switch (opc) {
                case 1:
                    RegistrarVendedor();
                    break;
                case 2:
                    RegistrarSupervisor();
                    break;
                case 3:
                    break;
                case 4:
                    RegistrarVendedorSupervisor();
                    break;
                case 5:
                    PromedioVentas();
                    break;
                case 6:
                    break;
                default:
                    System.out.println("Opcion incorrecta");
            }
        }while (opc != 6) ;

        }

    private static void RegistrarVendedor() {
        File archivo = new File("Vendedores.dat");
        ObjectOutputStream Output = null;
        FileOutputStream outputFile = null;

        Vendedor nuevoVendedor = ObtenerVendedor();

        try{
            outputFile = new FileOutputStream(archivo);
            Output = new ObjectOutputStream(outputFile);
            Output.writeObject(nuevoVendedor);

            outputFile.close();
            Output.close();
        }catch (Exception ex) {
            System.out.println("Un error ocurrio registrando vendedor " + ex);
        }
    }

    private static Vendedor ObtenerVendedor(){
        Scanner sc = new Scanner(System.in);

        String nombre;
        System.out.println("Ingresa el nombre a registrar:");
        nombre = sc.nextLine();

        System.out.println("Ingresa la edad:");
        int edad = sc.nextInt();

        System.out.println("Ingrese salario");
        double salario = sc.nextDouble();



        return new Vendedor(nombre, edad, salario);
    }

    private static void RegistrarSupervisor() {
        File archivo = new File("Supervisores.dat");
        ObjectOutputStream Output = null;
        FileOutputStream outputFile = null;

        Supervisor supervisor = obtenerSupervisor();

        try{
            outputFile = new FileOutputStream(archivo);
            Output = new append(outputFile);
            Output.writeObject(supervisor);

            outputFile.close();
            Output.close();
        }catch (Exception ex) {
            System.out.println("Un error ocurrio registrando supervisor " + ex);
        }
    }

    private static Supervisor obtenerSupervisor() {
        Scanner sc = new Scanner(System.in);

        String nombre;
        System.out.println("Ingresa el nombre a registrar:");
        nombre = sc.nextLine();

        System.out.println("Ingresa la edad:");
        int edad = sc.nextInt();

        System.out.println("Ingrese salario");
        double salario = sc.nextDouble();

        return new Supervisor(nombre, edad, salario);
    }

    private static void RegistrarVendedorSupervisor() {
        /*
        File archivo2 = new File("Supervisores.dat");
        File auxiliar = new File("auxiliar.dat");
        ObjectOutputStream Output = null;
        Scanner sc = new Scanner(System.in);
        FileOutputStream EscribirByte=null;
        ObjectOutputStream EscribirObjeto=null;
         */

        boolean finArchivo = false;
        Vendedor vendedorActual;
        boolean encontrado = false;

        // System.out.println("Ingrese el nombre del vendedor");
        // var nombre = sc.nextLine();

        File archivo = new File("Vendedores.dat");
        ObjectInputStream input=null;
        FileOutputStream outputFile=null;
        FileInputStream inputFile=null;

        try {
            inputFile = new FileInputStream(archivo);
            input = new ObjectInputStream(inputFile);

            while (!finArchivo){
                Vendedor obj = (Vendedor) input.readObject();
                System.out.println("" + obj.getNombre());
            }

        }catch (IOException | ClassNotFoundException ex) {
            finArchivo = true;
        }

        try {
            inputFile.close();
            input.close();
        } catch (IOException ex) {}

/*

        if (!encontrado) {
            System.out.println("no se encontro vendedor");
            return;
        }


        finArchivo = false;
        Supervisor supervisorActual;
        encontrado = false;


        System.out.println("Ingrese el nombre del supervisor");
        var nombre2 = sc.nextLine();

        try{

            LeerByte=new FileInputStream(archivo2);
            LeerObjeto=new ObjectInputStream(LeerByte);
            EscribirByte=new FileOutputStream(auxiliar);
            EscribirObjeto=new ObjectOutputStream(EscribirByte);

            while (!finArchivo) {
                Supervisor obj  = (Supervisor) LeerObjeto.readObject();
                if (obj.getNombre().equals(nombre2)) {
                    supervisorActual = obj;
                    obj.AgregarVendedor(ObtenerVendedor());
                }

                EscribirObjeto.writeObject(obj);

            }

        }catch (Exception ex){
            System.out.println("Un error leyendo los supervisor " + ex);
            finArchivo = true;
        }

 */


    }

    public static void PromedioVentas() {
        File archivo = new File("Vendedores.dat");
        ObjectInputStream input=null;
        FileOutputStream outputFile=null;
        FileInputStream inputFile=null;
        boolean finArchivo=false;
        Double suma = Double.valueOf(0);
        int count = 0;

        try {
            inputFile = new FileInputStream(archivo);
            input = new ObjectInputStream(inputFile);

            while (!finArchivo){
                Vendedor obj = (Vendedor) input.readObject();
                System.out.println("ventas " +  obj.getVentas());
                suma += obj.getVentas().stream().mapToDouble(a -> a).average().getAsDouble();
                count++;
            }

        }catch (Exception ex) {}

        try {
            inputFile.close();
            // input.close();
        } catch (IOException ex) {}

        System.out.println("EL PROMEDIO ES DE: " + (suma / count));

    }

}
