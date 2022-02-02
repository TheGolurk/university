package com.upemor;

import java.util.Scanner;

public class SegundoProblema {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Moneda m1 = new Moneda();
        Moneda m2 = new Moneda(23000.31);

        int opc = 0;

        do {
            System.out.println("1.- Convertir a dolar");
            System.out.println("2.- Convertir a euro");
            System.out.println("3.- Convertir a franco suizo");
            opc = sc.nextInt();

            switch (opc) {
                case 1 -> m2.ADolar();
                case 2 -> m2.AEuro();
                case 3 -> m2.AFranco();
                default -> System.out.println("Selecciona una opcion correcta");
            }
        }while(opc != 4);

    }
}
