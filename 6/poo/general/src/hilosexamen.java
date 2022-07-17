import java.util.ArrayList;

public class hilosexamen {
    public static void main(String[] args) throws InterruptedException {
        var nombre = "Christian";
        var sep = nombre.split("");
        var h1 = new h("C");
        var h2 = new h("H");
        var h3 = new h("R");
        var h4 = new h("I");
        var h5 = new h("S");


        h1.start();
        h1.join();
        h2.join();
        h3.join();
        h4.join();
        h5.join();

        h2.start();
        h3.start();
        h4.start();
        h5.start();

    }

}


