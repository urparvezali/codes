import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class z extends JFrame {
	private JTextField nameField, emailField;
	private JPasswordField passwordField;
	private JRadioButton maleRadio, femaleRadio;
	private JButton registerButton;

	public z() {
		setTitle("Registration Form");
		setSize(400, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new GridLayout(5, 2, 10, 10));

		// Name
		add(new JLabel("Name:"));
		nameField = new JTextField();
		add(nameField);

		// Email
		add(new JLabel("Email:"));
		emailField = new JTextField();
		add(emailField);

		// Password
		add(new JLabel("Password:"));
		passwordField = new JPasswordField();
		add(passwordField);

		// Gender
		add(new JLabel("Gender:"));
		JPanel genderPanel = new JPanel();
		maleRadio = new JRadioButton("Male");
		femaleRadio = new JRadioButton("Female");
		ButtonGroup genderGroup = new ButtonGroup();
		genderGroup.add(maleRadio);
		genderGroup.add(femaleRadio);
		genderPanel.add(maleRadio);
		genderPanel.add(femaleRadio);
		add(genderPanel);

		// Register Button
		registerButton = new JButton("Register");
		add(registerButton);

		// Button Click Event
		registerButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				showRegistrationDetails();
			}
		});

		// Make frame visible
		setVisible(true);
	}

	// Method to display entered details in a dialog box
	private void showRegistrationDetails() {
		String name = nameField.getText();
		String email = emailField.getText();
		String password = new String(passwordField.getPassword());
		String gender = maleRadio.isSelected() ? "Male" : femaleRadio.isSelected() ? "Female" : "Not Selected";

		String message = "Name: " + name + "\nEmail: " + email + "\nPassword: " + password + "\nGender: " + gender;
		JOptionPane.showMessageDialog(this, message, "Registration Details", JOptionPane.INFORMATION_MESSAGE);
	}

	public static void main(String[] args) {
		new z(); // Run the application
	}
}
