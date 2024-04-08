import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class SimpleSwingApp {
    public static void main(String[] args) {
        // Create a JFrame (window)
        JFrame frame = new JFrame("Simple Swing Application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 200);

        // Create a JPanel to hold components
        JPanel panel = new JPanel();

        // Create a JButton
        JButton button = new JButton("Click Me");
        panel.add(button);

        // Add the panel to the frame
        frame.add(panel);

        // Display the frame
        frame.setVisible(true);
    }
}
