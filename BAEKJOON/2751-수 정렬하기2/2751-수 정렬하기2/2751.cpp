#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int lIdx = left;
	int rIdx = mid + 1;
	int sIdx = left;

	int * sortArr = (int*)malloc(sizeof(int)*(right + 1));

	while (lIdx <= mid && rIdx <= right)
	{
		if (arr[lIdx] <= arr[rIdx])
			sortArr[sIdx++] = arr[lIdx++];
		else
			sortArr[sIdx++] = arr[rIdx++];
	}


	while (lIdx <= mid)
	{
		sortArr[sIdx++] = arr[lIdx++];
	}


	while (rIdx <= right)
	{
		sortArr[sIdx++] = arr[rIdx++];
	}


	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

int main()
{	
	int n,i;
	scanf("%d", &n);

	int * arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	MergeSort(arr, 0, n-1);

	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}