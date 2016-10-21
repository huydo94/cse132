package assignment10;
import java.io.*;
import java.util.ArrayList;
import assignment10.receive;
import assignment5.ViewOutputStream;
import java.io.BufferedReader;


public class fitbit {
	public static void main(String[] args) throws IOException {
		// FIXME Auto-generated method stub
		SerialComm s = new SerialComm();
        try {
			s.connect("COM10");
		} catch (Exception e) {
			// FIXME Auto-generated catch block
			e.printStackTrace();
		} // Adjust this to be the right port for your machine
        	InputStream in = s.getInputStream();
        	receive msg1 = new receive(in);
        	while(true){
        	msg1.run();
        	float[] zArray1 = msg1.getz();
        	short[] heartArray1 = msg1.getheart();
        	int steps = 0;
        	for (int k=0; k<=zArray1.length-2;k++){
        		if((zArray1[k]>0.5) && (zArray1[k+1]<0.5))
        			steps = steps +1;				        		
        	}
        	System.out.println(steps);
        	
        	double[] filterList = new double[heartArray1.length];
    		filterList[0]= 0.0;
    		filterList[1]= 0.0;
    		for (int j = 2;j<=heartArray1.length-3;j++){
    			filterList[j] = 0.01036382*heartArray1[j+2]-0.01036382*heartArray1[j]+1.9789467705*filterList[j-1]-0.97927235*filterList[j-2];
    			//System.out.println(filterList[j]);
    		}
    		int peak = 0;
    		for (int k=0; k<=heartArray1.length-2;k++){
    			if((filterList[k]>0) && (filterList[k+1]<0))
    				peak = peak +1;				
    		}
    		double heartrate = peak/(0.002*(heartArray1.length));
    		System.out.println(heartrate);
    		
    		OutputStream spit = s.getOutputStream();
    		ViewOutputStream abc = new ViewOutputStream(spit);
    		int y = (int) Math.round(heartrate);
    		byte[] heartlcd = new byte[2];
    		for (int u = 0; u < 2; u++) {
    			heartlcd[u] = (byte)(y >>> (u * 8));
    		}

    		
    		byte[] stepslcd = new byte[2];
    		for (int l = 0; l < 2; l++) {
    			stepslcd[l] = (byte)(steps >>> (l * 8));
    		}
    		abc.write(0x22);
    		abc.write(stepslcd);
    		abc.write(heartlcd);
    		//BufferedReader huy = new BufferedReader(new InputStreamReader(System.in));
    		//String text = huy.readLine(); // Program pauses here if there's no input
    		//if(text=="reset"){
    			//steps = 0;
    		//}    		
        }	
	}   	
}
