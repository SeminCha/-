import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
	    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();		
		String initText = bf.readLine();		
		int n = Integer.valueOf(bf.readLine());		
		int pos = initText.length();
		sb.append(initText);
		
		for(int i=0;i<n;i++) {	
			String [] line = bf.readLine().split(" ");
			
			switch(line[0]) {
			case "L" :
				if(pos>0)
					pos--;
				break;
			case "D" :
				if(pos<sb.length())
					pos++;
				break;
			case "B" :
				if(pos>0) {
					sb.deleteCharAt(pos-1);
					pos--;
				}				
				break;
			case "P" :
				sb.insert(pos, line[1]);
				pos++;
				break;
			}
		}		
		System.out.println(sb.toString());		
	}
}
