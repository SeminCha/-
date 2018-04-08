import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack<Character> stack; 
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		for(int i=0;i<n;i++) {
			char [] line = sc.nextLine().toCharArray();
			stack = new Stack<Character>();
			boolean check = true;
			int j=0;
			while(j<line.length) {
				if(line[j]=='(')
					stack.push('(');
				else {
					if(stack.empty()) {
						check = false;
						break;
					}				
					else {
						stack.pop();
					}						
				}
				j++;
			}
			if(stack.empty()&&check==true) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}

}
