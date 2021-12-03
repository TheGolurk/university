package com.upemor;

import java.util.HashMap;

public class ROMANO extends NUMERO {
    private HashMap<Character, Integer> map = new HashMap<>();

    public ROMANO(String digito) {
        super(digito);

        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
    }

    @Override
    public int obtenerValor() {

        var digito = getDigito().toUpperCase();
        int total  = 0;
        int atras = 0;

        for (int i = digito.length() - 1; i >= 0; i--) {

            var val1 =  map.get(digito.charAt(i));

            // REGLA 3 (DIGITO MENOR A LA IZQUIERDA)
            if (val1 < atras) {
                total -= val1;
            } else  { // ELSE LO CONTARIO, REGLA 2 (DIGITO MAYOR A LA DERECHA) // PODEMOS SALTARNOS CON ESTO LA REGLA 1
                total += val1;
            }
            atras = val1;

        }

        return total;
    }

}
