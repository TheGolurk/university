package org.example;


import com.github.javafaker.Faker;

import java.util.Random;

public class Main {

    private static Faker faker = new Faker();

    public static void main(String[] args) {

        Random r = new Random();

        Alumno[] grupo1 = new Alumno[
                r.ints(20,50).findFirst().orElse(0)
                ];
        Alumno[] grupo2 = new Alumno[
                r.ints(20,50).findFirst().orElse(0)
                ];

        llenarGrupo(grupo1);
        llenarGrupo(grupo2);
        imprimir(grupo1);
        imprimir(grupo2);
    }

    public static void llenarGrupo(Alumno[] alumnos) {
        for (int i = 0; i < alumnos.length; i++) {

            Materia[] materias = new Materia[10];
            for (int j = 0; j < materias.length; j++)  {
                var nom = faker.name().title();
                var cal = faker.number().numberBetween(0,100);

                materias[j] = new Materia(nom, cal);
            }

            alumnos[i] = new Alumno(
                    faker.name().firstName(),
                    faker.number().numberBetween(18, 70),
                    faker.code().isbn10(),
                    materias
            );
        }
    }

    public static void imprimir(Alumno[] alumnos) {
        for (int i = 0; i < alumnos.length; i++) {
            System.out.println("Alumno: " +
                    alumnos[i].getNombre() +
                    " tiene un promedio de: " +
                    alumnos[i].CalcularPromedio()
            );
        }
    }

}