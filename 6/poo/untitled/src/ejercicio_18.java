import java.util.ArrayList;
import java.util.Stack;

public class ejercicio_18 {
    public static void main(String[] args) {
        int numeros[] = {5,3,8,2};
        String operadores[] = {"+", "*", "/"};
        String ddasdads= "5+3*8/2";
        var res = ddasdads.split("");
        Stack<String> pilaOperadoresMayores = new Stack<>();
        Stack<String> pilaOperadoresMenores = new Stack<>();

        for (int i = 0; i < operadores.length; i++) {
            try {
                if (esSuperior(operadores[i], operadores[i+1])) {
                    if (iguales(operadores[i], operadores[i+1])) {
                        pilaOperadoresMayores.push(operadores[i+i]);
                    } else {
                        pilaOperadoresMayores.push(operadores[i]);
                    }
                } else {
                    pilaOperadoresMenores.push(operadores[i]);
                }
            }catch (ArrayIndexOutOfBoundsException ex) {
                if (esMayorMenor(operadores[i])) {
                    pilaOperadoresMayores.push(operadores[i]);
                } else {
                    pilaOperadoresMenores.push(operadores[i]);
                }

                System.out.println(ex);
            }
        }

        System.out.println("RESULTADO");

        for (int numero : numeros) {
            System.out.println(numero);
        }

        pilaOperadoresMayores.forEach(s -> {
            System.out.println(s);
        });

        pilaOperadoresMenores.forEach(s -> {
            System.out.println(s);
        });

    }

    public static boolean esSuperior(String operador1, String operador2) {
        if ((operador1.equals("+") || operador1.equals("-")) && (operador2.equals("*") || operador2.equals("/"))) {
            return false;
        } else if (operador1.equals("*") || operador1.equals("/") && (operador2.equals("+") || operador2.equals("-"))) {
            return true;
        }

        return false;
    }

    public static boolean iguales(String operador1, String operador2) {
        if (operador1.equals("/") && operador2.equals("*")) {
            return true;
        } else if (operador1.equals("+") && operador2.equals("-")) {
            return false;
        }

        return false;
    }


    // esMayorMenor
    // false menor
    // true mayor
    public static boolean esMayorMenor(String operador1) {
        if (operador1.equals("+") || operador1.equals("-")) {
            return false;
        } else return (operador1.equals("*") || operador1.equals("/"));
    }

}
