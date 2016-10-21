package assignment5;

import java.io.*;

import javax.swing.JFrame;
import studio4.PrintStreamPanel;

public class ViewOutputStream extends FilterOutputStream {

    final private PrintStreamPanel psp;
    final private PrintStream ps;

    public ViewOutputStream(OutputStream out) {
        super(out);
        JFrame f = new JFrame("ViewOutputStream");
		f.setBounds(100,100,225,300);
        psp = new PrintStreamPanel();
		f.getContentPane().add(psp);
		f.setVisible(true);
        ps = psp.getPrintStream(); 
    }

    public void write(String args) throws IOException {
        // TODO
        // use super.read() to access the next byte from the InputStream
        // also, you can use ps like System.out to print to the new window
    	byte[] data1 = args.getBytes();
    	super.write(data1);
    	ps.println(data1);
    }
    
}
