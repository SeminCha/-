#include<stdio.h>

void SelectionSort(int a[], int n)
{
	int maxIdx, temp;

	for (int i = 0; i < n - 1; i++)
	{
		maxIdx = n - 1 - i;

		for (int j = n - 2 - i; j >= 0; j--)
		{
			if (a[maxIdx] < a[j])
			{
				maxIdx = j;
			}
		}

		temp = a[n - 1 - i];
		a[n - 1 - i] = a[maxIdx];
		a[maxIdx] = temp;
	}
}

int main()
{
	int num, i;
	int arr[1000];

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	SelectionSort(arr, num);

	for (i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}


