package com.upemor;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);
    private static Biblioteca biblioteca = new Biblioteca();

    public static void main(String[] args) {
        Start();
    }

    public void registrarRestaurador() {
        System.out.println("Ingrese RFC");
        var RFC = sc.next();

        System.out.println("Ingrese sueldo");
        var Sueldo = sc.nextDouble();

        System.out.println("Ingrese nombre");
        var Nombre = sc.next();

        Restaurador restaurador = new Restaurador(Nombre,RFC,Sueldo);
        var res = biblioteca.RegistrarEmpleado(restaurador);
        if (res) {
            System.out.println("Restaurador registrado");
            return;
        }

        System.out.println("No se pudo registrar");
    }

    public static void Start() {
        var opc = 0;

        do {
            System.out.println("1.- Registrar libros");
            System.out.println("2.- Registrar usuarios");
            System.out.println("3.- Registrar empleados restauradores");
            System.out.println("4.- Registrar empleados administradores");
            System.out.println("5.- Registrar prestamo de un libro para un usuario");
            System.out.println("6.- Registrar libros a restaurar para empleado restaurador");
            System.out.println("7.- Registrar empleados restauradores para un empleado supervisor");
            System.out.println("8.- Salir");
            opc = sc.nextInt();

            switch (opc){
                case 1 -> {

                }
                case 2 -> {

                }
                case 3 -> {

                }
                case 4 -> {

                }
                case 5 -> {

                }
                case 6 -> {

                }
                case 7 -> {

                }
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
