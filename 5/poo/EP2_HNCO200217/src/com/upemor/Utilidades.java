package com.upemor;

import java.util.Scanner;

public class Utilidades {

    public Utilidades() {
    }

    public Sucursal ObtenerSucursal() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese direccion");
        String direccion = sc.nextLine();

        System.out.println("Datos del gerente");
       sc.nextLine();

        System.out.println("Nombre");
        String nombre = sc.nextLine();

        System.out.println("RFC");
        String rfc = sc.nextLine();

        System.out.println("Salario");
        Double salario = sc.nextDouble();

        return new Sucursal(direccion, new Gerente(nombre, rfc, salario), new Taller());
    }

    public Cliente ObtenerCliente(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese nombre:");
        String nombre =sc.nextLine();

        System.out.println("Ingresa edad:");
        int edad = sc.nextInt();

        sc.nextLine();
        System.out.println("Ingresa correo:");
        String correo = sc.nextLine();

        return new Cliente(nombre, edad, correo);
    }

    public Empleado ObtenerEmpleado(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese nombre:");
        String nombre =sc.nextLine();

        System.out.println("Ingresa rfc:");
        String rfc = sc.nextLine();

        System.out.println("Ingresa salario:");
        Double salario = sc.nextDouble();

        return new Empleado(nombre, rfc,salario);

    }

    public Compra ObtenerCompra() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese fecha:");
        String fecha =sc.nextLine();

        return new Compra(fecha, ObtenerAuto());

    }

    public Auto ObtenerAuto() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingrese modelo:");
        String modelo =sc.nextLine();

        System.out.println("Ingrese costo:");
        Double costo =sc.nextDouble();

        return new Auto(modelo, costo);
    }

    public Servicio ObtenerServicio() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese Nombre:");
        String nombre =sc.nextLine();

        System.out.println("Ingrese Descripcion:");
        String descripcion =sc.nextLine();

        System.out.println("Ingrese costo:");
        Double costo = sc.nextDouble();

        return new Servicio(nombre, descripcion,costo, ObtenerAuto());
    }

}
