#include<stdio.h>
#include<stdlib.h>

int result[500000];
int arr[500000];

// 오름차순
int compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int rFindElement(int arr[], int k, int left, int right)
{
	if (left > right)
		return 0;

	int mid = (left + right) / 2;

	if (k == arr[mid])
		return 1;
	else if (k < arr[mid])
		return rFindElement(arr, k, left, mid - 1);
	else
		return rFindElement(arr, k, mid + 1, right);
}

int main()
{
	int n, k, outputNum;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);
	scanf("%d", &outputNum);

	for (int i = 0; i < outputNum; i++)
	{
		scanf("%d", &k);
		result[i] = rFindElement(arr, k, 0, n - 1);
	}
	for (int i = 0; i < outputNum; i++)
		printf("%d ", result[i]);

	return 0;
}