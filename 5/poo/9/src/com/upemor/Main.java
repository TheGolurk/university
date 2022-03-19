package com.upemor;

import java.util.HashSet;

public class Main {

    public static void main(String[] args) {
        HashSet<Contacto> contactos = new HashSet<>();
        contactos.add(new Contacto("Lorena", "Valle", 20));
        contactos.add(new Contacto("Lorena", "Valle", 20));
        contactos.add(new Contacto("Lorena", "Valle", 20));

        contactos.add(new Contacto("asdadasd", "Valleasdas", 22));

        contactos.forEach(contacto -> {
            System.out.println(contacto.getNombre());
        });

    }
}
