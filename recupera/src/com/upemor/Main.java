package com.upemor;

// JAVA 17

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String numberRoman = "";

        System.out.println("INGRESA UN NUMERO EN ROMANO \n");
        numberRoman = sc.nextLine();


        ROMANO r = new ROMANO(numberRoman);
        System.out.printf("%d \n", r.obtenerValor());

    }

}
