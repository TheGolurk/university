package com.upemor;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);
    private static Biblioteca biblioteca = new Biblioteca();

    public static void main(String[] args) {
        Start();
    }

    public static void validarRegistrado(boolean res) {
        if (res) {
            System.out.println("Registrado");
            return;
        }

        System.out.println("No se pudo registrar");
    }

    public static void registrarRestaurador() {
        System.out.println("Ingrese RFC");
        var RFC = sc.next();

        System.out.println("Ingrese sueldo");
        var Sueldo = sc.nextDouble();

        System.out.println("Ingrese nombre");
        var Nombre = sc.next();

        Restaurador restaurador = new Restaurador(Nombre,RFC,Sueldo);
        validarRegistrado(
                biblioteca.RegistrarEmpleado(restaurador)
        );
    }

    public static void registrarSupervisor() {
        System.out.println("Ingrese RFC");
        var RFC = sc.next();

        System.out.println("Ingrese sueldo");
        var Sueldo = sc.nextDouble();

        System.out.println("Ingrese nombre");
        var Nombre = sc.next();

        Restaurador restaurador = new Restaurador(Nombre,RFC,Sueldo);
        validarRegistrado(
                biblioteca.RegistrarEmpleado(restaurador)
        );
    }

    public static void registrarLibro() {}

    public static void registrarUsuario() {}

    public static void registrarPrestamoLibro() {}

    public static void registrarLibroARestaurar() {}

    public static void registrarEmpleadoASupervisor() {}

    public static void Start() {
        var opc = 0;

        do {
            System.out.println("1.- Registrar libros");
            System.out.println("2.- Registrar usuarios");
            System.out.println("3.- Registrar empleados restauradores");
            System.out.println("4.- Registrar empleados supervisores");
            System.out.println("5.- Registrar prestamo de un libro para un usuario");
            System.out.println("6.- Registrar libros a restaurar para empleado restaurador");
            System.out.println("7.- Registrar empleados restauradores para un empleado supervisor");
            System.out.println("8.- Salir");
            opc = sc.nextInt();

            switch (opc){
                case 1 -> registrarLibro();
                case 2 -> registrarUsuario();
                case 3 -> registrarRestaurador();
                case 4 -> registrarSupervisor();
                case 5 -> registrarPrestamoLibro();
                case 6 -> registrarLibroARestaurar();
                case 7 -> registrarEmpleadoASupervisor();
                case 8 -> {
                    System.out.println("Adios");
                }
                default -> {
                    System.out.println("Opcion invalida");
                    return;
                }
            }
        }while (opc != 8);
    }

}
