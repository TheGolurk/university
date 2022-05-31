import javax.swing.*;
import java.awt.*;

public class DibujarOvalo extends JPanel {

    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        var x = 1;
        var y = 2;
        for (int i = 1; i < 20; i++) {
            g.drawOval(x, y, i + 10, i + 20);
            x+=7;
            y+=7;
        }

    }

}
