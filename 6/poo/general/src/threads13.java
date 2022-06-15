public class threads13 {

    public static void main(String[] args) {
        Thread hilo1 = new proceso("proceso 1");
        Thread hilo2 = new proceso("proceso 2");
        hilo1.start();
        hilo2.start();

    }

}
