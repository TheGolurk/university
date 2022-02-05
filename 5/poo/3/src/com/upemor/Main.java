package com.upemor;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Materia[] materias = new Materia[3];

        for (int i = 0; i < materias.length; i++)  {
            System.out.println("Ingresa nombre");
            var nom = sc.next();

            System.out.println("Ingresa calificacion");
            var cal = sc.nextDouble();

            materias[i] = new Materia(nom, cal);
        }

        Alumno a1 = new Alumno("Juan", 10, "QWEASD123", materias);

        a1.ConsultarCalificaciones();

        System.out.println("Alumno: " + a1.getNombre() + " tiene un promedio de: " + a1.CalcularPromedio());

    }
}
