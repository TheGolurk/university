import java.util.Scanner;

public class Main0905 {
    public static void main(String[] args) {

        int a[] = {2,4,8,16,32,64,128,256,512,1024};
        int b[] = {0,0,0,2,1,1,34,43};

        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < a.length; i++) {
            try {
                var v = b[i];
                var s = a[i] / v;
                System.out.printf("%d / %d = %s \n", a[i], v, s);
            }catch (ArrayIndexOutOfBoundsException ex) {
                System.err.println("No hay valores en esta posicion");
            }catch (ArithmeticException ex) {
                System.out.println("No se puede dividir por este valor");
            }
        }

    }
}
