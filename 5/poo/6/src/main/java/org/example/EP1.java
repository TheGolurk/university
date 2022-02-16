package org.example;

import java.util.Scanner;

public class EP1 {

    private static Scanner leer = new Scanner(System.in);

    public static void main(String[] args) {

        int opcion = 0;

        //opciones de problemas
        System.out.println("-----MENU------");
        System.out.println("Problema 1:Fecha");
        System.out.println("Problema 2:Fraccion");
        System.out.println("Problema 3:Conjunto");
        System.out.println("----------------");
        System.out.println("Ingresa el numero de problema a elegir:\n");
        opcion = leer.nextInt();


        switch (opcion) {
            case 1 -> Problema1();
            case 2 -> Problema2();
            case 3 -> Problema3();
            default -> System.out.println("Opcion incorrecta");
        }

    }

    //Fecha
    public static void Problema1() {
        Fecha f1 =  new Fecha(30, 1, 2022);
        int opcion=0;

        System.out.println("1. Validar fecha");
        System.out.println("2. Fecha Siguiente");
        System.out.println("3. Fecha Anterior");
        System.out.println("4. Diferencia de Fecha");
        System.out.println("Ingrese la opcion a elegir:");
        var opc = leer.nextInt();

        switch (opc) {
            case 1 -> {
                var fecha = ObtenerFecha();
                System.out.printf("Fecha valida? %b \n", fecha.FechaValida());
            }
            case 2 -> {
                System.out.println("Ingrese fecha");
                var fecha = ObtenerFecha();
                var dias = leer.nextInt();
                var res = fecha.FechaSiguiente(fecha, dias);
                System.out.printf("%d/%d/%d \n", res.getDia(), res.getMes(), res.getAño());
            }
            case 3 -> {
                System.out.println("Ingrese fecha");
                var fecha = ObtenerFecha();
                var dias = leer.nextInt();
                var res = fecha.FechaAnterior(fecha, dias);
                System.out.printf("%d/%d/%d \n", res.getDia(), res.getMes(), res.getAño());
            }
            case 4 -> {
                System.out.println("Ingrese fecha");
                var fecha = ObtenerFecha();
                System.out.println("Ingrese otra fecha");
                var fecha2 = ObtenerFecha();

                var res = fecha.Diferencia(fecha, fecha2);
                System.out.println("La diferencia es de: " + res);
            }
            default -> System.out.println("Opcion invalida");
        }

    }

    private static Fecha ObtenerFecha() {
        System.out.println("Ingrese el dia");
        var dia = leer.nextInt();
        System.out.println("Ingrese el mes");
        var mes = leer.nextInt();
        System.out.println("Ingrese año");
        var año = leer.nextInt();

        return new Fecha(dia, mes, año);
    }

    //Fraccion
    public static void Problema2() {

        System.out.println("1.-Suma");
        System.out.println("2.-Resta");
        System.out.println("3.-Multiplicacion");
        System.out.println("4.-Division");
        System.out.println("Ingrese la opcion a elegir:");
        var opc = leer.nextInt();

        switch (opc){
            case 1 ->{
                var fraccion = ObtenerFraccion();
                System.out.println("Ingrese otra fraccion para realizar la operacion");
                var fraccion2 = ObtenerFraccion();
                fraccion.Sumar( fraccion2.getNumerador(), fraccion2.getDenominador() );
            }

            case 2->{

                var fraccion= ObtenerFraccion();
                System.out.println("Ingrese otra fraccion para realizar la operacion");
                var fraccion2 = ObtenerFraccion();
                fraccion.Restar( fraccion2.getNumerador(), fraccion2.getDenominador());


            }

            case 3->{

                var fraccion= ObtenerFraccion();
                System.out.println("Ingrese otra fraccion para realizar la operacion");
                var fraccion2 = ObtenerFraccion();
                fraccion.Multiplicar( fraccion2.getNumerador(), fraccion2.getDenominador());
            }

            case 4->{

                var fraccion= ObtenerFraccion();
                System.out.println("Ingrese otra fraccion para realizar la operacion");
                var fraccion2 = ObtenerFraccion();
                fraccion.Division( fraccion2.getNumerador(), fraccion2.getDenominador());

            }

            default-> System.out.println("Opcion incorrecta");
        }
    }

    private static Fraccion ObtenerFraccion() {
        System.out.println("Ingresa numerador");
        var num = leer.nextInt();
        System.out.println("Ingresa denominador");
        var den = leer.nextInt();
        return new Fraccion(den,num);
    }

    //Conjunto
    public static void Problema3() {

        var opc = 0;
        Conjunto c =  new Conjunto();
        do {
            System.out.println("1.-Agregar");
            System.out.println("2.-Eliminar");
            System.out.println("3.-Union");
            System.out.println("4.-Union sobrecargada");
            System.out.println("5.-Interseccion");
            System.out.println("6.-Interseccion sobrecargada");
            System.out.println("7.-Diferencia");
            System.out.println("8.-Diferencia sobrecargada");
            System.out.println("9.-Salir");
            System.out.println("Ingrese la opcion a elegir:");
            opc = leer.nextInt();

            switch (opc) {

                case 1 -> {
                    System.out.println("Ingrese el dato a agregar");
                    var dato = leer.nextInt();
                    System.out.println("Ingrese el conjunto a agregar 1.- Conjunto A | 2.- Conjunto B");
                    var con =  leer.nextInt();
                    c.Agregar(dato, con);
                }

                case 2 -> {
                    System.out.println("Ingrese el dato a eliminar");
                    var dato = leer.nextInt();
                    System.out.println("Ingrese el conjunto a eliminar 1.- Conjunto A | 2.- Conjunto B");
                    var con =  leer.nextInt();
                    c.Eliminar(dato, con);
                }

                case 3 -> {
                   c.Union();
                   c.imprimir();
                }

                case 4 -> {
                    c.UnionSobrecargada(ObtenerConjunto());
                    c.imprimir();
                }

                case 5 -> {
                    c.Interseccion();
                    c.imprimir();
                }

                case 6 -> {
                    c.interseccionSobrecargada(ObtenerConjunto());
                    c.imprimir();
                }

                case 7 -> {
                    c.Diferencia();
                    c.imprimir();
                }

                case 8 -> {
                    c.DiferenciaSobrecargada(ObtenerConjunto());
                    c.imprimir();
                }
                default -> System.out.println("Opcion incorrecta");
            }
        } while (opc != 9);
    }

    public static int[] ObtenerConjunto() {
        int[] a = new int[100];
        System.out.println("Elija un numero entre 1 a 100 para llenar el conjunto");
        var max = leer.nextInt();

        for (int i = 0; i < max; i++) {
            System.out.println("Ingrese un valor");
            a[i] = leer.nextInt();
        }

        return a;
    }
}