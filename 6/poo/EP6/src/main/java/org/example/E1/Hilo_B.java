package org.example.E1;

import java.util.Random;


/**
 *
 * @author joyke
 */
public class Hilo_B {
    public static void main(String[] args) {
        HilosDesordenados hilo=new HilosDesordenados();
        HilosDesordenados2 hilo3=new HilosDesordenados2();
        System.out.println("Hilo #1 Inicia");
        System.out.println("Hilo #2 Inicia");
        hilo.start();
        hilo3.start();
    }
}

class HilosDesordenados extends Thread{
    Integer [] a = new Integer[10];
    int res=0;

    @Override
    public void run(){
        Random rand= new Random();
        int maximo = 1000;
        for (int i = 0; i < a.length; i++) {
            a[i]=rand.nextInt(maximo);
        }
        for (int i = 0; i < a.length; i++) {
            res+=a[i];
            if(i == 0){
                System.out.println("Acumulado hilo#1 es: " +a[i]);
            }else{
                System.out.println("Acumulado hilo#1 es: "+res);
            }
        }
        System.out.println("Hilo #1 Terminado");
        System.out.println("Suma Total Hilo #1 es " +res);
    }
}

class HilosDesordenados2 extends Thread{
    Integer [] b = new Integer[10];
    int res=0;

    @Override
    public void run(){
        Random rand= new Random();
        int maximo = 1000;
        for (int i = 0; i < b.length; i++) {
            b[i]=rand.nextInt(maximo);
        }

        for (int i = 0; i < b.length; i++) {
            res+=b[i];
            if(i == 0){
                System.out.println("Acumulado hilo#2 es: " +b[i]);
            }else{
                System.out.println("Acumulado hilo#2 es: "+res);
            }
        }
        System.out.println("Hilo #2 Terminado");
        System.out.println("Suma Total Hilo #2 es " +res);
    }
}

