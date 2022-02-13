package org.example;

import java.util.Scanner;

public class EP1 {

    public static void main(String[] args) {

        Scanner leer = new Scanner(System.in);

        int opcion = 0;

        System.out.println("Problema 1");
        System.out.println("Problema 2");
        System.out.println("Problema 3");
        System.out.println("Ingresa una opcion");
        // opcion = leer.nextInt();
        opcion = 1;

        switch (opcion) {
            case 1 -> Problema1();
            case 2 -> Problema2();
            case 3 -> Problema3();
            default -> System.out.println("Opcion incorrecta");
        }

    }

    public static void Problema1() {
        Fecha f1 =  new Fecha(30, 1, 2022);
        f1.FechaSiguiente(f1, 40);
        f1.FechaAnterior(f1, 40);
    }

    public static void Problema2() {

    }

    public static void Problema3() {

    }

}
