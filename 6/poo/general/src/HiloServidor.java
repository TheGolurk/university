public class HiloServidor extends Thread {
    private String data;
    private String add;

    public HiloServidor(String data, String addr) {
        this.data = data;
        this.add = addr;
    }

    @Override
    public void run() {
        System.out.println("" + add + "  " + data);
    }
}
