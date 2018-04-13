import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] line = sc.nextLine().split(" ");
		int e = 0, s = 0, m = 0;
		int earth = Integer.valueOf(line[0]);
		int sun = Integer.valueOf(line[1]);
		int moon = Integer.valueOf(line[2]);

		int year = 0;
		while (true) {
			year++;
			e += 1;
			s += 1;
			m += 1;
			if (e == 16) {
				e = 1;
			}
			if (s == 29) {
				s = 1;
			}
			if (m == 20) {
				m = 1;
			}
			/*
			 * e = year%15; if(e==0) { e++; } s = year%28; if(s==0) { s++; } m = year%19;
			 * if(m==0) { m++; }
			 */
			if (e == earth && s == sun && m == moon) {
				break;
			}
		}
		System.out.println(year);
	}
}
