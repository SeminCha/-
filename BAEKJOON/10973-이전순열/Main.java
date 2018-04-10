import java.util.*;

public class Main {

	public static boolean nextPermutation(int[] arr) {
		int i, j, temp;

		for (i = arr.length - 1; i > 0; i--) {
			if (arr[i] < arr[i - 1]) {
				break;
			}
		}

		if (i == 0) {
			return false;
		}

		for (j = arr.length - 1; j >= i; j--) {
			if (arr[j] < arr[i - 1]) {
				temp = arr[j];
				arr[j] = arr[i - 1];
				arr[i - 1] = temp;
				break;
			}
		}

		int s = i;
		int e = arr.length - 1;
		while (s < e) {
			temp = arr[s];
			arr[s] = arr[e];
			arr[e] = temp;
			s++;
			e--;
		}

		return true;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }

		if (nextPermutation(arr)) {
			for (int i = 0; i < n; i++) {
				System.out.print(arr[i] + " ");
			}
		} else {
			System.out.println(-1);
		}
	}
}
