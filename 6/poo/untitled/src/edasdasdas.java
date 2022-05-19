import java.util.InputMismatchException;
import java.util.Scanner;

public class edasdasdas {
    public static void main(String[] args) {

        Scanner sc =  new Scanner(System.in);
        int n1 = 0, n2 = 0;

        boolean a = false;
            try {

                System.out.println("0");
                n1 = sc.nextInt();
                System.out.println("1");
                n2 = sc.nextInt();


                int resultado = n1 / n2;

            } catch (ArithmeticException ex) {
                System.out.println("no se divid en 0" + ex);
            } catch (InputMismatchException ex) {
                System.out.println("ingresa un entero" + ex);
            }

    }
}
