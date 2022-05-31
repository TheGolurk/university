import javax.swing.*;
import java.awt.*;

public class DibujarCirculo extends JPanel {

    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        var x = 100;
        var y = 70;
        for (int i = 1; i < 20; i++) {
            // g.drawRoundRect(x, y, i + 10 * 2 * i, i + 20 * 2 * i, 50 ,100 );
            g.drawArc(x, y, i + 10 * 2 * i, i + 10 * 2 * i, 0 ,180 );
            g.drawArc(x, y, i + 10 * 2 * i, i + 10 * 2 * i, 180 ,180 );
            x -= 10;
            y -= 10;
        }

    }

}
