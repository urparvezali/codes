import javax.swing.*;
import java.awt.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class APP extends JFrame {
    JTextField rollField = new JTextField(10);
    JTextField nameField = new JTextField(10);
    JTextField marksField = new JTextField(10);
    JButton enterButton = new JButton("Enter");
    JButton doneButton = new JButton("Done");

    public APP() {
        setTitle("Student Information");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 200);

        JPanel panel = new JPanel(new GridLayout(4, 2));

        JLabel[] labels = { new JLabel("Roll Number:"), new JLabel("Student Name:"), new JLabel("Marks:") };
        JTextField[] fields = { rollField, nameField, marksField };

        enterButton.addActionListener(e -> {
            String rollNumber = rollField.getText(), name = nameField.getText(), marks = marksField.getText();
            if (!rollNumber.isEmpty() && !name.isEmpty() && !marks.isEmpty()) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter("student_info.txt", true))) {
                    writer.write("Roll Number: " + rollNumber + "\nStudent Name: " + name + "\nMarks: " + marks + "\n\n");
                    JOptionPane.showMessageDialog(null, "Student information added successfully.");
                } catch (IOException ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(null, "Error writing to file.");
                }
            } else {
                JOptionPane.showMessageDialog(null, "Please fill in all fields.");
            }
        });

        doneButton.addActionListener(e -> dispose());

        for (int i = 0; i < labels.length; i++) {
            panel.add(labels[i]);
            panel.add(fields[i]);
        }
        panel.add(enterButton);
        panel.add(doneButton);

        add(panel);
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(APP::new);
    }
}
