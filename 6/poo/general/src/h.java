public class h extends Thread {
    private String letra;

    public h(String letra) {
        this.letra = letra;
    }

    public void setLetra(String letra) {
        this.letra = letra;
    }

    @Override
    public void run() {
        System.out.println("" + this.letra);
    }

}