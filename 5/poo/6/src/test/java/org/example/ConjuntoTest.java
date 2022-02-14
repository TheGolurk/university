package org.example;

import org.junit.Test;
import org.junit.jupiter.api.Assertions;

import java.util.Arrays;

public class ConjuntoTest {

    @Test
    public void Conjuntos() {
        int[] a = new int[10];
        int[] b = new int[10];
        Conjunto c1 = new Conjunto(a, b);
        c1.Agregar(1, 1);
        c1.Agregar(2,1);
        c1.Agregar(3,1);

        c1.Agregar(4,2);
        c1.Agregar(1, 2);
        c1.Agregar(5, 2);
        c1.Agregar(2, 2);

        var res = c1.Union();
        int[] exp = {1,2,3,4,1,5,2};
        Assertions.assertEquals(exp[0], res[0]);
        Assertions.assertEquals(exp[4], res[4]);

        int[] c3 = {1,5,6,8};
        res = c1.DiferenciaSobrecargada(c3);
        var match = Arrays.stream(res).anyMatch(x -> x == 3);
        Assertions.assertTrue(match);


        res = c1.Interseccion();
        match = Arrays.stream(res).anyMatch(x -> x == 1);
        Assertions.assertTrue(match);

        match = Arrays.stream(res).anyMatch(x -> x == 2);
        Assertions.assertTrue(match);

        c1.Eliminar(5, 2);
        match = Arrays.stream(res).anyMatch(x -> x == 5);
        Assertions.assertFalse(match);
    }

}
