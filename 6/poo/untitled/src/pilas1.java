import java.util.Stack;

public class pilas1 {
    public static void main(String[] args) {

        Stack<Integer> s = new Stack<Integer>();
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        System.out.println("Elementos en la pila son: " + s);

        System.out.println("La posicion del indice 10 esta en: " + s.search(10));
        System.out.println("La posicion del indice 50 esta en: " + s.search(50));

        int x = s.pop();
        System.out.println("Elemento que se eliminara de la pila es:: " + x);

        x = s.pop();
        System.out.println("Elemento que se eliminara de la pila es:: " + x);

        x = s.pop();
        System.out.println("Elemento que se eliminara de la pila es:: " + x);

        x = s.pop();
        System.out.println("Elemento que se eliminara de la pila es:: " + x);

    }
}
