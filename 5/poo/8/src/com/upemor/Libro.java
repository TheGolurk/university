package com.upemor;

public class Libro {
    private String Titulo;
    private String Autor;
    private String Editorial;
    private String ISBN;

    public Libro(String titulo, String autor, String editorial, String ISBN) {
        Titulo = titulo;
        Autor = autor;
        Editorial = editorial;
        this.ISBN = ISBN;
    }
}
