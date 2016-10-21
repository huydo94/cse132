package assignment5;

import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import studio4.SerialComm;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;

public class SerialOuput {
	static SerialComm huy = new SerialComm();
	public static void main(String[] args) throws Exception {
		// FIXME Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		huy.connect("COM13");
		OutputStream spit = huy.getOutputStream();
		ViewOutputStream abc = new ViewOutputStream(spit);
		while(true){
			String text = in.readLine();
			System.out.println(text);
			byte[] b = text.getBytes();
			abc.write(b);
	
		}
	}	
}
