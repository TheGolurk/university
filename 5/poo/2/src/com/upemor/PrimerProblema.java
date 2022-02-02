package com.upemor;

import java.util.Random;
import java.util.Scanner;

public class PrimerProblema {

    public static void main(String[] args) {

        Random r = new Random();

        int [][]sales = new int[3][12];

        for (int i = 0; i < sales.length; i++) {
            for (int j = 0; j < sales[i].length; j++) {
                sales[i][j] = r.ints(20000, 50000).findFirst().orElse(0);
            }
        }

        int opc;
        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("1.- Average");
            System.out.println("2.- Greater than in sales");
            System.out.println("3.- Minus than in sales");
            opc = sc.nextInt();

            switch (opc) {
                case 1 -> {
                    int []itemsFiltered = new int[6];
                    int index = 0;
                    for (int i = 6; i < 12; i++) {
                        itemsFiltered[index] = sales[1][i];
                        index++;
                    }

                    // easiest way
                    // var avg = Arrays.stream(itemsFiltered).average().orElse(0);
                    var avg = average(itemsFiltered);
                    System.out.println("Average is: " + avg);
                }

                case 2 -> {
                    int prev = average(sales[0]);
                    int max = 0;
                    for (int i = 0; i < sales.length; i++) {
                        if (average(sales[i]) > prev) {
                            max = i;
                        }
                    }
                    greater(max);
                }

                case 3 -> {
                    var avg = average(sales[0]);
                    calculateSales(avg, sales);
                }

                case 4 -> System.out.println("GOOD BYE");
            }
        }while (opc != 4);

    }

    public static void greater(int value)  {
        switch (value+1) {
            case 1 -> System.out.println("department 1 mayor");
            case 2 -> System.out.println("department 2 mayor");
            case 3 -> System.out.println("department 3 mayor");
            default -> System.out.println("Invalid department");
        }
    }

    public static void calculateSales(int avg, int[][] sales) {
        int sum = 0;
        int index = 0;

        for (int i = 1; i < sales.length; i++) {
            for (int j = 0; j < sales[i].length ; j++) {

                sum += sales[i][j];
                index++;
                if (sum > avg) {
                    sum -= sales[i][j];
                    index--;
                }
            }
        }

        System.out.println("amount of months: " + index);
    }

    public static int average(int []sales) {
        int sum = 0;
        for (int sale : sales) {
            sum += sale;
        }
        
        return sum/sales.length;
    }

}
