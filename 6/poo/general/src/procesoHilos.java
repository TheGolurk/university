public class procesoHilos extends Thread {
    private String nombre;
    private int iter;

    public procesoHilos(String nombre, int iter) {
        this.nombre = nombre;
        this.iter = iter;
    }

    public void empezar() {
        this.start();
    }

    @Override
    public void run() {
        for (int i = 0; i < iter; i++) {
            System.out.println(nombre+i);
        }
    }

    public static void main(String[] args) {
        new procesoHilos("i1", 10).empezar();
        new procesoHilos("i2", 10).empezar();
        new procesoHilos("i3", 10).empezar();
    }


}
