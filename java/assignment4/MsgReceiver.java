package assignment4;

import studio4.SerialComm;
import java.io.*;

public class MsgReceiver {

	final private ViewInputStream vis;
	
	public MsgReceiver(InputStream in) {
		vis = new ViewInputStream(in);
	}
	public enum State {waitingforMagicNumber, waitingforinputtype, readingtime, readingrawtemp, debugging,readingfiltertemp, readpot};

	public void run() throws IOException {
		// insert code here
		// read from vis and write to console
		DataInputStream what = new DataInputStream(vis);
		State state = State.waitingforMagicNumber;
		
		while(true){
			int avl = what.available();
			if (avl>0){
				State nextState = State.waitingforMagicNumber;
				switch(state){
					case waitingforMagicNumber:
						int data = what.read();
						if (data == 33){
							nextState = State.waitingforinputtype;
						}else{
							nextState = State.waitingforMagicNumber;
						}
						break;
					case waitingforinputtype:
						int cond = what.read();
						if (cond == 50){
							nextState = State.readingtime;
						} else if (cond == 48) {
							nextState = State.debugging;
						} else if (cond == 52) {
							nextState = State.readingrawtemp;
						} else if (cond == 54) {
							nextState = State.readingfiltertemp;
						} else if (cond == 51) {
							nextState = State.readpot;
						}else{
							nextState = State.waitingforMagicNumber;
						}
						break;
					case readingtime:
						int thetime = what.readInt();
						System.out.print("The current time is:  ");
		            	System.out.println(thetime);
		            	nextState = State.waitingforMagicNumber;
		            	break;
					case readingrawtemp:
						float rawtemp = what.readFloat();
						System.out.print("The raw temp is:   ");
						System.out.println(rawtemp);
						nextState = State.waitingforMagicNumber;
						break;
					case readingfiltertemp:
						float filter = what.readFloat();
						System.out.print("The filtered temp is:   ");
						System.out.println(filter);
						nextState = State.waitingforMagicNumber;
						break;
					case readpot:
						short pot = what.readShort();
						System.out.print("The pot reading is:   ");
						System.out.println(pot);
						nextState = State.waitingforMagicNumber;
						break;
					case debugging:
						String debugmess = what.readUTF();
						System.out.println(debugmess);
						nextState = State.waitingforMagicNumber;
		            default:
		            	System.out.println();
		            	break;
				}
			state = nextState;
			}
				//String data = what.readUTF();
            	//System.out.println(times);        
			}
		}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
        try
        {        	
            SerialComm s = new SerialComm();
            s.connect("COM5"); // Adjust this to be the right port for your machine
            InputStream in = s.getInputStream();
            MsgReceiver msgr = new MsgReceiver(in);
            msgr.run();
        }
        catch ( Exception e )
        {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

	}

}
