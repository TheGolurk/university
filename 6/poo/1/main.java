public class ejemplo {

    public static void main(){

        Scanner sc = new Scanner(System.in);

        int num1 = 0, num2 = 0, num3 = 0;

        num1 = readNum();
        num2 = readNum();
        num3 = readNum();


    }

    public static int readNum() {
        int base = 0;
        Scanner sc = new Scanner(System.in);
        boolean valid = false;

        do {
            try {
                base = sc.nextInt();  
                valid = true;    
            } catch (Execption e) {
                valid = false;                
            }
        }while(valid);

        return base;
    }

}