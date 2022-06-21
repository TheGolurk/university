public class hiloParametro extends Thread{

    private int numero;

    public hiloParametro(int numero) {
        this.numero = numero;
    }

    @Override
    public void run() {
        System.out.println("holi " + this.numero);

    }
}
