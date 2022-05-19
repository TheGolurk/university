import java.util.Stack;

public class pilassuma {
    private static int suma = 0;
    private static final Stack<Integer> pila = new Stack();

    public static void main(String[] args) {
        sumar(10);
        sumar(20);
        sumar(30);
        sumar(40);
        sumar(50);

        System.out.println("El valor actual es:" + suma);

        quitar();
        quitar();
        System.out.println("El valor actual es:" + suma);

    }

    public static void sumar(int num) {
        pila.push(num);
        suma += num;
        System.out.println("El valor actual es:" + suma);

    }

    public static void quitar() {
        System.out.println("La ultima operacion se quito:");
        suma -= pila.pop();

    }
}
