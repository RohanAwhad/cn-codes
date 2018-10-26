import java.net.*;
import java.io.*;
import java.nio.charset.*;

public class Client {
	public static void main(String args[]) throws Exception {
		DatagramSocket s = new DatagramSocket(1080);
		InetAddress addr = InetAddress.getLocalHost();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str1 ="";
		byte[] buf = new byte[1000];
		byte[] buf1 = new byte[1000];

		while(!str1.equals("Bye")) {
			str1 = br.readLine();
			buf =  str1.getBytes();
			DatagramPacket p1 = new DatagramPacket(buf,buf.length,addr,1090);
			s.send(p1);
			buf=null;
			DatagramPacket p2 = new DatagramPacket(buf1,buf1.length);
			s.receive(p2);
			buf1= p2.getData();
			String str2 = new String(buf1,StandardCharsets.UTF_8);
			System.out.println("Server says " + str2);
		}
	}
}
