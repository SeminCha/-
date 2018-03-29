#include<stdio.h>

int main()
{
	int numOfBox, count = 0;;
	int arr[1000];
	int dp[1000] = { 0, };
	int max=0;

	scanf("%d", &numOfBox);
	for (int i = 0; i < numOfBox; i++)
	{
		scanf("%d", &arr[i]);
		if (dp[i] == 0)
			dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
			if (max < dp[i])
				max = dp[i];
		}
	}

	printf("%d", max);
	return 0;
}