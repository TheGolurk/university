package com.upemor;

public class DistEjecutable {

    public static void main(String[] args) {
        double [] a = {1,2,3,4,5};
        double [] b = {6,7,8,9,10};
        Distancias d1 = new Distancias(5, 10, a,b);
        Distancias d2 = new Distancias(6, 14, a,b);

        System.out.println(d1.Euclidiana(d2));
        System.out.println(d1.Manhattan());
        System.out.println(d1.Minkowski(2));

    }
}
