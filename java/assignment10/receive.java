
package assignment10;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

import assignment10.SerialComm;
import assignment10.ViewInputStream;

public class receive {
	
	final private ViewInputStream vis;
	public receive(InputStream in) {
		// FIXME Auto-generated constructor stub
		vis = new ViewInputStream(in);
	}
	public enum State {waitingforMagicNumber, waitingforinputtype, readX, readY, readZ,readheart};
	ArrayList<Float> zList = new ArrayList<Float>();
	ArrayList<Short> heartList = new ArrayList<Short>();
	public void run() throws IOException {
		// insert code here
		DataInputStream what = new DataInputStream(vis);
		State state = State.waitingforMagicNumber;
		for(int h=0;h<500000;h++){
		//while(true){
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
						if (cond == 52){
							nextState = State.readZ;
						} else if (cond == 53) {
							nextState = State.readheart;
						}else{
							nextState = State.waitingforMagicNumber;
						}
						break;
					case readZ:
						float zvalue = what.readFloat();
						//System.out.println(zvalue);
						zList.add(zvalue);	
						nextState = State.waitingforMagicNumber;
						break;
					case readheart:
						short pulsevalue = what.readShort();
						//System.out.println(pulsevalue);
						heartList.add(pulsevalue);
						nextState = State.waitingforMagicNumber;
						break;
					default:
						nextState = State.waitingforMagicNumber;
						break;
				}
				state = nextState;
			}
		}
	}
	public float[] getz(){
		float[] zArray = new float[zList.size()];
		for (int i = 1;i <= zList.size()-1;i++){
			zArray[i]=zList.get(i);
			//System.out.println(valuelist[i]);		
		}
		return zArray;
	}
	public short[] getheart(){
		short[] heartArray = new short[heartList.size()];
		for (int j = 1;j <= heartList.size()-1;j++){
			heartArray[j]=heartList.get(j);
		}
		return heartArray;
	}

	public static void main(String[] args) {
		// FIXME Auto-generated method stub
		try
        {        	
            SerialComm s = new SerialComm();
            s.connect("COM13"); // Adjust this to be the right port for your machine
            InputStream in = s.getInputStream();
            receive msgr = new receive(in);
            msgr.run();
        }
        catch ( Exception e )
        {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
	}

}
