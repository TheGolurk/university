import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        var res = Integer.parseInt(JOptionPane.showInputDialog("1 2"));

        JPanel panel = null;
        switch (res) {
            case 1 -> {
                panel = new DibujarRectangulo();
            }
            case 2 -> {
                panel = new DibujarOvalo();
            }
            case 3 -> {
                panel = new DibujarCirculo();
            }
            default -> System.out.println("incorrecto");
        }

        JFrame app = new JFrame();
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        app.add(panel);
        app.setSize(250,250);
        app.setVisible(true);

    }
}