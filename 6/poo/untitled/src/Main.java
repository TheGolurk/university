import java.util.Scanner;

public class Main {

    private static Double num,num1, rest;
    private static boolean error;

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        error = false;

        try {
            System.out.println("Dame el primer Número");
            num=teclado.nextDouble();
            System.out.println("Dame el segundo Número");
            num1=teclado.nextDouble();
            resta rest = new resta(num, num1);
            rest.hacerResta();

        } catch (Exception e) {
            error=true;
            System.out.println("Error la exepción es : "+ e);

        }
        finally{
            if(error == true)
                System.out.println("Ocurrio un Error en el código");
            else
                System.out.println("El programa corrio satistafactoriamente");
        }
    }
}