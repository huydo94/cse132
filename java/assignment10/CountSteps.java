package assignment10;
import java.io.*;
import java.util.ArrayList;

import assignment4.MsgReceiver;

public class CountSteps {

	public static void main(String[] args) throws IOException {
		// FIXME Auto-generated method stub
		//MsgReceiver msg = new MsgReceiver;
		//msg.run
		FileReader fr = new FileReader("data/studio9/steps.csv");
		BufferedReader huy = new BufferedReader(fr);
		String line = null;
		ArrayList<Float> xValue = new ArrayList<Float>();
		
		while ((line = huy.readLine())!=null){
			String[] data = line.split(",");
			float value = Float.parseFloat(data[0]); //get the x values
			xValue.add(value);
			//System.out.println(value); //print out the x values
		}
		huy.close();
		double[] xArray = new double[xValue.size()];
		for (int i = 1;i <= xValue.size()-1;i++){
			xArray[i]=xValue.get(i);
			//System.out.println(valuelist[i]);
		}
		int steps = 0;
		for (int k=0; k<=xValue.size()-2;k++){
			if((xArray[k]>0) && (xArray[k+1]<0))
				steps = steps +1;				
		}
		System.out.println(steps);
	}
}
