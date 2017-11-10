#include <stdio.h>

void rFindWorm(int arr[][50], int garo, int sero, int bottom, int right)
{
	if (garo > bottom || garo < 0)
		return;

	if (sero > right || sero < 0)
		return;

	arr[garo][sero] = 2;

	//위쪽 검사
	if (arr[garo - 1][sero] == 1)
		rFindWorm(arr, garo - 1, sero, bottom, right);

	//오른쪽 검사
	if (arr[garo][sero + 1] == 1)
		rFindWorm(arr, garo, sero + 1, bottom, right);

	//아래쪽 검사
	if (arr[garo + 1][sero] == 1)
		rFindWorm(arr, garo + 1, sero, bottom, right);

	//왼쪽 검사
	if (arr[garo][sero - 1] == 1)
		rFindWorm(arr, garo, sero - 1, bottom, right);

	arr[garo][sero] = 0;
}

int findWorm(int arr[][50], int garoTotal, int seroTotal)
{
	int i, j;
	int count = 0;

	for (i = 0; i < garoTotal; i++)
	{
		for (j = 0; j < seroTotal; j++)
		{
			if (arr[i][j] == 1)
			{
				rFindWorm(arr, i, j, garoTotal - 1, seroTotal - 1);
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int count, i, j;
	int garoTotal, seroTotal, locationTotal;
	int garo, sero;	
	int result;

	scanf("%d", &count);

	for (i = 0; i < count; i++)
	{
		int arr[50][50] = {0,};
		scanf("%d %d %d", &garoTotal, &seroTotal, &locationTotal);
		for (j = 0; j < locationTotal; j++)
		{
			scanf("%d %d", &garo, &sero);
			arr[garo][sero] = 1;
		}

		result = findWorm(arr, garoTotal, seroTotal);
		printf("%d\n", result);
	}

	return 0;
}