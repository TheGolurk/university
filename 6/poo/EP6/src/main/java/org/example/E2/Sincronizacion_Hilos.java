package org.example.E2;

import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Sincronizacion_Hilos {

    private ArrayList<Integer> numeros;
    private Thread hilo;

    public Sincronizacion_Hilos() {
        numeros = new ArrayList<Integer>();
        Random r = new Random();
        int num = r.nextInt(10 - 1) + 1;
        for (int i = 0; i < num; i++) {
            numeros.add(r.nextInt(10 - 1) + 1);

        }
        this.asignar();
    }

    public void empezar(){
        hilo.start();

    }

    private void asignar() {
        hilo = new Thread(new Runnable() {
            int contador = 0;
            int suma =0;
            @Override
            public void run() {
                numeros.forEach(e -> {

                    Thread h;
                    h = new Thread(new Runnable() {
                        public void run() {
                            try {
                                System.out.println(" CLIENTE: "+contador+" TIEMPO: "+e +" DURACION TOTAL: "+suma);
                                Thread.sleep(e*1000);
                                suma = suma+e;
                            } catch (InterruptedException ex) {
                                Logger.getLogger(Sincronizacion_Hilos.class.getName()).log(Level.SEVERE, null, ex);
                            }


                        }

                    });

                    h.start();
                    try {
                        h.join();
                    } catch (InterruptedException ex) {
                        Logger.getLogger(Sincronizacion_Hilos.class.getName()).log(Level.SEVERE, null, ex);
                    }

                    contador++;
                });

            }

        });
    }
    public static void main(String[] args) {
        Sincronizacion_Hilos hilo_nuevo = new Sincronizacion_Hilos();
        hilo_nuevo.empezar();

    }



}
