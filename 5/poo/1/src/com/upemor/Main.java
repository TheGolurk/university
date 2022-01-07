package com.upemor;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    // openjdk 11.0.13 2021-10-19

        Scanner sc = new Scanner(System.in);

        // 1
        ArrayList<Integer> data = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter a value: ");
            data.add(sc.nextInt());
        }

        data.forEach((value) -> {
            if (value % 2 != 0) {
                System.out.println(value);
            }
        });

        // 2
        ArrayList<Integer> matriz = new ArrayList<>();
        matriz.add(1);
        matriz.add(2);
        matriz.add(3);
        matriz.add(4);
        matriz.add(5);
        matriz.add(6);
        matriz.add(7);
        matriz.add(8);
        matriz.add(9);

        average(matriz);

    }

    public static void average(ArrayList<Integer> matriz) {
        // Immutable values
        System.out.println(
                "promedio: " +
                matriz.stream().reduce(0, (a,b) -> a+b) / matriz.size()
        );
    }
}
