package com.upemor;

import java.util.Date;

public class Prestamo {
    private Date FechaPrestamo;
    private Date FechaRegreso;

    public Prestamo(Date fechaPrestamo, Date fechaRegreso, com.upemor.Libro libro) {
        FechaPrestamo = fechaPrestamo;
        FechaRegreso = fechaRegreso;
        Libro = libro;
    }

    private Libro Libro;

    public Prestamo() {

    }
}
