import java.util.*;

public class Main {

	public static void findKth(int[] arr, int n, long count) {
		int i, j;
		int[] check = new int[n];

		for (i = 0; i < n; i++) {
			long temp = factorial(n - i - 1);
			for (j = 0; j < n; j++) {
				if (check[j] == 0) {
					if (count - temp > 0) {
						count -= temp;
					} else {
						check[j] = 1;
						arr[i] = j + 1;
						break;
					}
				}
			}
		}
	}

	public static long findOrder(int[] arr, int n) {
		int i, j;
		long temp;
		long count = 0;
		int[] check = new int[n];

		for (i = 0; i < n; i++) {
			temp = factorial(n - i - 1);
			for (j = 0; j < n; j++) {
				if (check[j] == 0) {
					if (arr[i] == j + 1) {
						check[j] = 1;
						break;
					} else {
						count += temp;
					}
				}
			}
		}

		return count+1;
	}

	public static long factorial(int n) {
		if (n <= 1)
			return 1;
		else {
			return n * factorial(n - 1);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		String[] line = sc.nextLine().split(" ");
		int[] arr = new int[n];
		int i;

		if (Integer.valueOf(line[0]) == 1) {
			// 몇번째 순열인지를 입력받은 경우
			for (i = 0; i < n; i++) {
				arr[i] = i + 1;
			}
			findKth(arr, n, Long.valueOf(line[1]));

			for (i = 0; i < n; i++) {
				System.out.print(arr[i] + " ");
			}
		} else {
			// 임의의 순열을 입력받은 경우
			for (i = 0; i < n; i++) {
				arr[i] = Integer.valueOf(line[i + 1]);
			}
			System.out.println(findOrder(arr,n));
		}

	}
}
