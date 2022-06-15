public class procesoMain2 {

    private String nombre;
    private int iter;

    public procesoMain2(String nombre, int iter) {
        this.nombre = nombre;
        this.iter = iter;
    }


    public void ejecutar() {
        for (int i = 0; i < iter; i++) {
            System.out.println(nombre + i);
        }
    }

    public static void main(String[] args) {
        procesoMain2 i1 = new procesoMain2("i1", 10);
        procesoMain2 i2 = new procesoMain2("i2", 10);
        procesoMain2 i3 = new procesoMain2("i3", 10);
        Runnable r = i1::ejecutar;
        Runnable r2 = i2::ejecutar;
        Runnable r3 = i3::ejecutar;
        new Thread(r).start();
        new Thread(r2).start();
        new Thread(r3).start();
    }
}
