#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long sum = 0;

void swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int inPlacePartition(int arr[], int left, int right, int pivotIdx)
{
	int pivot = arr[pivotIdx];
	int low = left; // �ǹ��� ������ ���� ���ʿ� ��ġ�� ������ ����Ű�� ���� - �ǹ����� �켱������ ���� ��(���������̹Ƿ� ū ��)�� ���������� ������ �������� �̵�
	int high = right - 1; // �ǹ��� ������ ���� �����ʿ� ��ġ�� ������ ����Ű�� ���� - �ǹ����� �켱������ ���� ��(���������̹Ƿ� ���� ��)�� ���������� ���� �������� �̵�

	while (low <= high) // �������� ���� ������ �ݺ�
	{
		// �ǹ����� ū ���� ã�� ����
		while (pivot >= arr[low] && low <= right - 1)
			low++;

		// �ǹ����� ���� ���� ã�� ����
		while (pivot <= arr[high] && high >= left)
			high--;

		// �������� ���� ���¶�� swap ����
		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, right, low); // �ǹ��� low�� ����Ű�� ��� ��ȯ
	return low; // �Ű��� �ǹ��� ��ġ���� ��ȯ
}

void inPlaceQuickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int pivotIdx = inPlacePartition(arr, left, right, right); // �ѷ� ������ ����
	inPlaceQuickSort(arr, left, pivotIdx - 1); // ���� ������ ����
	inPlaceQuickSort(arr, pivotIdx + 1, right); // ������ ������ ����
	
}

void findMidium(int arr[], int tempArr[], int n, int k, int startIdx)
{
	int endIdx = startIdx + k;

	if (endIdx > n + 1)
		return;
	
	int midiumIdx = (k + 1) / 2;
	int j = 0;

	memcpy(tempArr, arr, sizeof(arr));
	

	inPlaceQuickSort(tempArr, startIdx, startIdx + k - 1);
	int midium = tempArr[midiumIdx+startIdx-1];	
	sum = sum + midium;	
	findMidium(arr,tempArr, n, k, ++startIdx);
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	int * arr = (int*)malloc(sizeof(int)*(n + 1));
	int * tempArr = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		tempArr[i] = arr[i];
	}

	findMidium(arr, tempArr, n, k, 1);
	printf("%lld\n", sum);
	free(arr);
	free(tempArr);
	return 0;
}


/*for (int i = startIdx; i <= startIdx + k - 1; i++)
{
tempArr[j] = arr[i];
j++;
}	*/
