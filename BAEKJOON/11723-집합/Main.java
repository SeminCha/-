import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		HashSet<String> set = new HashSet<String>();
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(bf.readLine());
		
		for(int i=0;i<n;i++) {
			String [] line = bf.readLine().split(" ");
			switch(line[0]) {
			case "add" :				
					set.add(line[1]);
				break;
			case "remove" :				
					set.remove(line[1]);
				break;
			case "check" : 
				if(set.contains(line[1]))
					System.out.println(1);
				else
					System.out.println(0);
				break;
			case "toggle" : 
				if(set.contains(line[1]))
					set.remove(line[1]);
				else
					set.add(line[1]);
				break;
			case "all" : 				
				String elements[] = { "1", "2", "3", "4", "5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
				set = new HashSet<String>(Arrays.asList(elements));
				break;
			case "empty" : 
				set.removeAll(set);
				break;
			}
		}
	}
}