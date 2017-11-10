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
	int low = left; // 피벗을 제외한 가장 왼쪽에 위치한 지점을 가리키는 변수 - 피벗보다 우선순위가 낮은 값(오름차순이므로 큰 값)을 만날때까지 오른쪽 방향으로 이동
	int high = right - 1; // 피벗을 제외한 가장 오른쪽에 위치한 지점을 가리키는 변수 - 피벗보다 우선순위가 높은 값(오름차순이므로 작은 값)을 만날때까지 왼쪽 방향으로 이동

	while (low <= high) // 교차되지 않을 때까지 반복
	{
		// 피벗보다 큰 값을 찾는 과정
		while (pivot >= arr[low] && low <= right - 1)
			low++;

		// 피벗보다 작은 값을 찾는 과정
		while (pivot <= arr[high] && high >= left)
			high--;

		// 교차되지 않은 상태라면 swap 실행
		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, right, low); // 피벗과 low가 가리키는 대상 교환
	return low; // 옮겨진 피벗의 위치정보 반환
}

void inPlaceQuickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int pivotIdx = inPlacePartition(arr, left, right, right); // 둘로 영역을 나눔
	inPlaceQuickSort(arr, left, pivotIdx - 1); // 왼쪽 영역을 정렬
	inPlaceQuickSort(arr, pivotIdx + 1, right); // 오른쪽 영역을 정렬
	
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
