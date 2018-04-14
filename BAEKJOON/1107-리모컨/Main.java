import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] broken = new int[10];
		int totalCount, totalCount1, totalCount2, upDownCount;
		int case1,case2;
		StringBuilder sb= new StringBuilder();
		String ch = sc.nextLine();
		int brokenCount = sc.nextInt();
		for (int i = 0; i < brokenCount; i++) {
			int brokenCh = sc.nextInt();
			broken[brokenCh] = 1;
		}

		for(int i=0;i<ch.length();i++) {
			int num = Character.getNumericValue(ch.charAt(i));

			//고장난 경우
			if(broken[num]==1) {
				int minCh = 0, min = 9, diff = 0;
				for (int j = 0; j <= 9; j++) {
					if(broken[j]==0) {
						if (num > j) {
							diff = num - j;
						} else {
							diff = j - num;
						}
						if (min > diff) {
							minCh = j;
							min = diff;
						}
					}
				}
				sb.append(minCh);
			} else {
				sb.append(num);
			}
		}

		case1=Integer.valueOf(sb.toString());
		sb = new StringBuilder();
		for(int i=0;i<ch.length()+1;i++) {
			for (int j = 0; j <= 9; j++) {
				if(broken[j]==0) {
					if(i==0&&j==0)
						continue;
					sb.append(j);
					break;
				}
			}
		}

		case2=Integer.valueOf(sb.toString());

		if(Integer.valueOf(ch)>case1) {
			totalCount1 = Integer.valueOf(ch)-case1+ch.length();
		} else {
			totalCount1 = case1-Integer.valueOf(ch)+ch.length();
		}

		if(Integer.valueOf(ch)>case2) {
			totalCount2 = Integer.valueOf(ch)-case2+ch.length()+1;
		} else {
			totalCount2 = case2-Integer.valueOf(ch)+ch.length()+1;
		}

		if(totalCount1>totalCount2)
			totalCount = totalCount2;
		else
			totalCount = totalCount1;

		if(Integer.valueOf(ch)>100) {
			upDownCount = Integer.valueOf(ch)-100;
		} else {
			upDownCount = 100-Integer.valueOf(ch);
		}

		if(totalCount>upDownCount) {
			System.out.println(upDownCount);
		} else {
			System.out.println(totalCount);
		}
	}
}
