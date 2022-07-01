package org.example.E1;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author joyke
 */
public class Hilo_A{

    public static void main(String[] args) {
        multihilos hilo=new multihilos();
        //multihilos2 hilo1=new multihilos2(hilo);
        multihilos3 hilo3=new multihilos3();
        //multihilos4 hilo4=new multihilos4(hilo3);
        System.out.println("Hilo #1 Inicia");
        System.out.println("Hilo #2 Inicia");
        hilo.start();
        try {
            hilo.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Hilo_A.class.getName()).log(Level.SEVERE, null, ex);
        }
        hilo3.start();
        try {
            hilo3.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Hilo_A.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

class multihilos extends Thread{
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

class multihilos2 extends Thread{
    public multihilos2(Thread hilo1){
        this.hilo=hilo1;
    }
    @Override
    public void run(){

        try {
            hilo.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(multihilos2.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
    private Thread hilo;
}

class multihilos3 extends Thread{
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
class multihilos4 extends Thread{
    public multihilos4(Thread hilo3){
        this.hilo=hilo3;
    }
    @Override
    public void run(){

        try {
            hilo.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(multihilos4.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
    private Thread hilo;
}
