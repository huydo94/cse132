package assignment10;
import java.io.*;
import java.util.ArrayList;

public class ButterFilter {

	public static void main(String[] args) throws IOException {
		// FIXME Auto-generated method stub
		FileReader fr = new FileReader("data/studio10/heart.csv");
		BufferedReader huy = new BufferedReader(fr);
		String line = null;
		ArrayList<Double> tempList = new ArrayList<Double>();

		while ((line = huy.readLine())!=null){
			String[] data = line.split(",");
			double value = Float.parseFloat(data[0]);
			tempList.add(value);
			//System.out.println(value); //print out the x values
		}
		huy.close();
		double[] valuelist = new double[tempList.size()];
		for (int i = 1;i <= tempList.size()-1;i++){
			valuelist[i]=tempList.get(i);
			//System.out.println(valuelist[i]);
		}
		double[] filterList = new double[tempList.size()];
		filterList[0]= 0.0;
		filterList[1]= 0.0;
		for (int j = 2;j<=tempList.size()-3;j++){
			filterList[j] = 0.01036382*valuelist[j+2]-0.01036382*valuelist[j]+1.9789467705*filterList[j-1]-0.97927235*filterList[j-2];
			//System.out.println(filterList[j]);
		}
		int peak = 0;
		for (int k=0; k<=tempList.size()-2;k++){
			if((filterList[k]>0) && (filterList[k+1]<0))
				peak = peak +1;				
		}
		System.out.println(peak);
	}
}
