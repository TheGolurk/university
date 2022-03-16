package com.upemor;

import java.time.LocalDate;
import java.util.Date;

public class Prestamo {
    private LocalDate FechaPrestamo;
    private LocalDate FechaRegreso;
    private Libro Libro;

    public Prestamo(LocalDate fechaPrestamo, Libro libro) {
        FechaPrestamo = fechaPrestamo;
        Libro = libro;
    }

    public void setFechaRegreso(LocalDate fechaRegreso) {
        FechaRegreso = fechaRegreso;
    }
}
