import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StudentInfoApp extends JFrame {

    private JLabel nameLabel, rollLabel, marksLabel;
    private JTextField[] nameFields, rollFields, marksFields;
    private JButton submitButton;

    public StudentInfoApp() {
        setTitle("Student Information App");
        setSize(400, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(6, 3, 10, 10));

        nameLabel = new JLabel("Name");
        rollLabel = new JLabel("Roll Number");
        marksLabel = new JLabel("Marks");

        nameFields = new JTextField[5];
        rollFields = new JTextField[5];
        marksFields = new JTextField[5];

        for (int i = 0; i < 5; i++) {
            nameFields[i] = new JTextField();
            rollFields[i] = new JTextField();
            marksFields[i] = new JTextField();

            add(new JLabel("Student " + (i + 1)));
            add(nameFields[i]);
            add(rollFields[i]);
            add(rollLabel);
            add(rollFields[i]);
            add(marksFields[i]);
        }

        submitButton = new JButton("Submit");
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                for (int i = 0; i < 5; i++) {
                    String name = nameFields[i].getText();
                    String roll = rollFields[i].getText();
                    String marks = marksFields[i].getText();
                    System.out.println("Student " + (i + 1) + ":");
                    System.out.println("Name: " + name);
                    System.out.println("Roll Number: " + roll);
                    System.out.println("Marks: " + marks);
                    System.out.println();
                }
            }
        });

        add(new JLabel()); // Empty cell
        add(submitButton);
        add(new JLabel()); // Empty cell

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new StudentInfoApp();
            }
        });
    }
}
