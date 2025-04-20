import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Z {

	public static void main(String[] args) {
		String url = "jdbc:mysql://localhost:3306/mydatabase";
		String user = "your_username"; // Replace with your database username
		String password = "your_password"; // Replace with your database password

		try (Connection connection = DriverManager.getConnection(url, user, password);
				Statement statement = connection.createStatement();
				ResultSet resultSet = statement.executeQuery("SELECT id, name, salary FROM employees")) {

			System.out.println("Connected to the database successfully!");
			System.out.println("Employee Data:");
			while (resultSet.next()) {
				int id = resultSet.getInt("id");
				String name = resultSet.getString("name");
				double salary = resultSet.getDouble("salary");
				System.out.println("ID: " + id + ", Name: " + name + ", Salary: " + salary);
			}

		} catch (SQLException e) {
			System.err.println("Error connecting to the database or executing the query: " + e.getMessage());
		}
	}
}