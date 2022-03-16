package com.upemor;

import javax.swing.plaf.synth.SynthOptionPaneUI;
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

    public static Restaurador obtenerRestaurador() {
        System.out.println("Ingrese RFC");
        var RFC = sc.next();

        System.out.println("Ingrese sueldo");
        var Sueldo = sc.nextDouble();

        System.out.println("Ingrese nombre");
        var Nombre = sc.next();

        return new Restaurador(Nombre,RFC,Sueldo);
    }

    public static void registrarSupervisor() {
        validarRegistrado(
                biblioteca.RegistrarEmpleado(
                        obtenerRestaurador()
                )
        );
    }

    public static Libro obtenerLbro(){
        System.out.println("Titulo");
        var Titulo = sc.next();

        System.out.println("Autor");
        var Autor = sc.next();

        System.out.println("Editorial");
        var Editorial = sc.next();

        System.out.println("ISBN");
        var ISBN = sc.next();

        return new Libro(Titulo, Autor, Editorial, ISBN);
    }

    public static void registrarLibro() {
        validarRegistrado(
                biblioteca.RegistrarLibro(
                        obtenerLbro()
                )
        );
    }

    public static void registrarUsuario() {
        System.out.println("Numero registro");
        var NumReg = sc.nextInt();

        System.out.println("Nombre");
        var Nombre = sc.next();

        System.out.println("Direccion");
        var Direccion = sc.next();

        System.out.println("Telefono");
        var Telefono = sc.next();

        Usuario usuario = new Usuario(NumReg, Nombre, Direccion, Telefono);
        validarRegistrado(
                biblioteca.RegistrarUsuario(usuario)
        );
    }

    public static void registrarPrestamoLibro() {
        System.out.println("Ingrese NumeroRegistro");
        var num = sc.nextInt();

        biblioteca.getUsuarios().forEach(usuario -> {
            if (usuario.getNumeroRegistro() == num) {

                usuario.SolicitarNuevoLibro(
                        obtenerLbro()
                );

            }
        });
    }

    public static void registrarLibroARestaurar() {
        System.out.println("Ingrese RFC");
        var rfc = sc.next();

        System.out.println("Ingrese ISBN");
        var isbn = sc.next();

        // Search employee
        biblioteca.getEmpleados().forEach(empleado -> {

            if (empleado.getRFC().equals(rfc)) {

                // Search book
                biblioteca.getLibros().forEach(libro -> {

                    // Match book and add to employee to restore
                    if (libro.getISBN().equals(isbn)) {
                        var res = (Restaurador) empleado;
                        res.AgregarLibroARestaurar(libro);
                    }

                });

            }

        });

    }

    public static void registrarEmpleadoASupervisor() {
        System.out.println("RFC del supervisor");
        var RFC = sc.next();

        biblioteca.getEmpleados().forEach(empleado -> {

            // We know that this RFC becomes from a supervisor, and we can cast the employee
            if (empleado.getRFC().equals(RFC)) {
                var sup = (Supervisor) empleado;

                sup.AgregarEmpleadoAcargo(
                        obtenerRestaurador()
                );
                
            }
        });
    }

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
