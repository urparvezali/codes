import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
	public static void main(String[] args) throws IOException {
		byte[] buffer = new byte[100];
		Scanner sc = new Scanner(System.in);
		
		while (true) {
			Socket socket = new Socket("localhost", 8000);
			String msg = sc.nextLine();
			InputStream is = socket.getInputStream();
			OutputStream os = socket.getOutputStream();

			os.write(msg.getBytes());
			os.flush();

			// wait to get return msg
			int len = is.read(buffer);
			String retured_msg = new String(buffer, 0, len);
			System.out.println(retured_msg);

			socket.close();
		}
	}
}
