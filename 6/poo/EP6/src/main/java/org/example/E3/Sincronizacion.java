package org.example.E3;

import java.util.Random;

public class Sincronizacion extends Thread {

    private static int[] a = new int[10];
    private static int[] b = new int[15];
    private static int suma = 0;
    private static int suma2 = 0;

    private int inicio;
    private int fin;
    private int inicio2;
    private int fin2;

    public Sincronizacion(int inicio, int fin, int inicio2, int fin2) {
        this.inicio = inicio;
        this.fin = fin;
        this.inicio2 = inicio2;
        this.fin2 = fin2;
    }

    @Override
    public void run() {

            System.out.println("Acumulando hilo #1 es " + suma);
            for (int i = inicio; i < fin; i++) {
                suma += a[i];
            }


            System.out.println("Acumulando hilo #2 es " + suma2);
            for (int i = inicio2; i < fin2; i++) {
                suma2 += b[i];
            }
    }


    public static void llenar() {
        Random r = new Random();

        for (int i = 0; i < 10; i++) {
            a[i] = r.nextInt(10 - 1) + 1;
        }
        for (int i = 0; i < 15; i++) {
            b[i] = r.nextInt(10 - 1) + 1;
        }
    }

    public static void empezar() throws InterruptedException {
        int nucleo = Runtime.getRuntime().availableProcessors();
        int inicio = 0, fin = 0, inicio2 = 0, fin2 = 0;
        Sincronizacion[] p = new Sincronizacion[nucleo];

        for (int i = 0; i < nucleo; i++) {
            inicio = fin;
            fin += a.length / nucleo;
            inicio2 = fin2;
            fin2 += b.length / nucleo;

            p[i] = new Sincronizacion(inicio, fin, inicio2, fin2);
            p[i].start();
            p[i].join();
        }
    }

    public static void main(String[] args) throws InterruptedException {
        llenar();

        empezar();
    }

}
