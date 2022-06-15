public class proceso extends Thread{
    public proceso(String s) {
        super(s);
    }

    @Override
    public void run(){
        for (int i = 0; i < 10; i++) {
            System.out.println(i + " " + getName());
        }
    }
}
