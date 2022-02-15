package org.example;

import org.junit.Test;
import org.junit.jupiter.api.Assertions;

public class FechaTest {

    private final Fecha f1 = new Fecha(30, 1, 2022);

    @Test
    public void TestFechaAnterior() {
        Fecha f2 = new Fecha(30,1,2022);

        Fecha nueva = f2.FechaAnterior(f2, 40);
        Assertions.assertEquals(21, nueva.getDia());

        Fecha f3 = new Fecha(30,1,2022);
        Fecha nueva2 = f2.FechaAnterior(f3, 120);
        Fecha postNueva2 = new Fecha(2, 10, 2021);
        Assertions.assertEquals(postNueva2.getDia(), nueva2.getDia());

        Fecha f4 = new Fecha(30,1, 2022);
        var res = f2.FechaAnterior(f4, 10);
        Assertions.assertEquals(20, res.getDia());
    }

    @Test
    public void TestFechaSiguiente() {
        Fecha f2 = new Fecha(30, 1, 2022);
        var res = f1.FechaSiguiente(f2, 120);
        Assertions.assertEquals(30, res.getDia());

        Fecha f3 = new Fecha(30, 1, 2022);
        res = f1.FechaSiguiente(f3, 400);
        Assertions.assertEquals(2023, res.getAño());
        Assertions.assertEquals(3, res.getMes());
        Assertions.assertEquals(6, res.getDia());

        Fecha f4 = new Fecha(30, 1, 2022);
        res = f1.FechaSiguiente(f4, 10);
        Assertions.assertEquals(9, res.getDia());
    }

}
