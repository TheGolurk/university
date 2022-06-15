public class threads132 {

    public static void main(String[] args) {
        new Thread(() -> {
            for (; ; ) {
                char ch;
                for (ch = 'A'; ch <= 'Z'; ch++) {
                    System.out.println(ch);
                }
            }
        }).start();

        new Thread(() -> {
            for (; ; ) {
                char ch;
                for (ch = 'a'; ch <= 'z'; ch++) {
                    System.out.println(ch);
                }
            }
        }).start();

        new Thread(() -> {
            for (; ; ) {
                for (int i = 0; i < 10; i++) {
                    System.out.println(i);
                }
            }
        }).start();
    }
}
