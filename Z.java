import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;;

public class Z extends JFrame {
	public Z() {
		super("MyWindowTitle");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setAlwaysOnTop(true);
		setSize(600, 300);
		setLayout(new FlowLayout());

		JTextField field = new JTextField(20);
		add(field);

		JButton button = new JButton("Click");
		add(button);
		button.addActionListener(new MyAction(field));
		setVisible(true);
	}

	public static void main(String[] args) {
		new Z();
	}
}

class MyAction implements ActionListener {
	JTextField field;

	public MyAction(JTextField field) {
		this.field = field;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println(field.getText());
		field.setText(null);
	}
}