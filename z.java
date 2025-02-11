public class z {
	public static void main(String[] args) {
		Client client = new Client();
		client.setName("Manob");
		client.showName();
	}
}

class Client {
	private String name;

	public void setName(String name) {
		this.name = name;
	}
	public void showName() {
		System.out.println(name);
	}
}