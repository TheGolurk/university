package com.upemor;

public class Main {

    public static void main(String[] args) {

        Persona p1 = new Persona("Lorena", "Valle", "VAlGL060102", 1.67f, 56.0f);
        System.out.printf("Datos de persona: %.1f kgs %.1f m \n",p1.getPeso(), p1.getAltura());

        System.out.printf("%.1f kgs %.1f m \n", p1.Andar(), p1.Comer());
        p1.Crecer();

        System.out.printf("Despues de hacer actividades: %.1f kgs %.1f m \n",p1.getPeso(), p1.getAltura());

        Mujer m1 = new Mujer("Mujer", "Sonia", "Perez", "asdasd", 1.65f, 60.0f);
        System.out.printf("Me llamo: %s, soy: %s\n",m1.getNombre(), m1.getGenero());

        Hombre h1 = new Hombre("Hombre", "Carlos", "Alberto", "123123", 1.80f, 800.f);
        System.out.printf("Me llamo: %s, soy: %s\n",h1.getNombre(), h1.getGenero());

        p1.Reproducirse();
        p1.Morir();
    }
}
