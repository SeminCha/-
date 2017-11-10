#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, isExist = 0;
	char c;
	int arr[26] = { 0, };
	char name[31];

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%s", &name);	
		++arr[(int)name[0] - 97];
	}

	for (i = 0; i < 26; i++)
	{
		if (arr[i] >= 5)
		{
			isExist = 1;
			printf("%c", (char)(i + 97));
		}
	}

	if (!isExist)
		printf("PREDAJA");

	return 0;
}