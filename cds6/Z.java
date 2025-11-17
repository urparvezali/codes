import java.io.*;
import java.net.*;

public class Z {

	public static void main(String[] args) throws IOException {
		final int PORT = 8000;

		try (ServerSocket serverSocket = new ServerSocket(PORT)) {
			System.out.println("HTTP Server is listening on port " + PORT);
			while (true) {
				Socket clientSocket = serverSocket.accept();
				System.out.println("New client connected");
				handleClient(clientSocket);
			}

		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void handleClient(Socket clientSocket) throws IOException {
		InputStream input = clientSocket.getInputStream();
		System.out.println("ready to read data");
		byte[] bytes = new byte[1000];
		int x = input.read(bytes);
		System.out.println("readed all bytes " + x);

		System.out.println("Closed reading stream");
		String data = new String(bytes);

		System.out.println(data);

		OutputStream output = clientSocket.getOutputStream();
		output.write(data.getBytes());
		output.flush();
		clientSocket.close();
	}
}

// class Udp {
// public static void run() throws IOException {
// try (DatagramSocket socket = new DatagramSocket(8080);) {
// byte[] buffer = new byte[100];
// while (true) {
// DatagramPacket request = new DatagramPacket(buffer, 100);
// socket.receive(request);

// var client_addr = request.getAddress();
// var client_port = request.getPort();

// String msg = new String(request.getData(), 0, request.getLength());
// System.out.println(msg);

// DatagramPacket response = new DatagramPacket(("Returned " + msg).getBytes(),
// ("Returned " + msg).getBytes().length, client_addr,
// client_port);

// socket.send(response);
// }
// }
// }
// }
