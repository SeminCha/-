#include <stdio.h>

int n;

void setArray(int arr[][16], int input, int line)
{
	int result;

	for (int i = 0; i < n; i++)
	{
		result = input % 2;
		input = input / 2;
		arr[line][n - i - 1] = result;
		if (input == 0)
			return;
	}
}

int main()
{
	int i, input;
	int arr1[16][16] = { 0, };
	int arr2[16][16] = { 0, };
	char str[16][16];

	printf("n : ");
	scanf("%d", &n);

	printf("arr1 : ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);
		setArray(arr1, input, i);
	}

	printf("arr2 : ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);
		setArray(arr2, input, i);
	}

	printf("Ãâ·Â : ");
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr1[i][j] || arr2[i][j])
				str[i][j] = '#';
			else
				str[i][j] = ' ';

			printf("%c", str[i][j]);
		}
		printf(", ");
	}
	
}