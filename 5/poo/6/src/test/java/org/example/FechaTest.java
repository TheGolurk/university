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

        Fecha nueva2 = f2.FechaAnterior(f2, 120);
        Fecha postNueva2 = new Fecha(2, 10, 2021);
        Assertions.assertEquals(postNueva2.getDia(), nueva2.getDia());
    }

}
