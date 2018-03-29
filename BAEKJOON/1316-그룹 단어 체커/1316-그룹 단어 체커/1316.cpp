#include <stdio.h>

int groupCharNum = 0;

int checkGroup(char input[])
{
	int j = 0;
	int lastIndex = 0;
	int arr[26] = { 0, };
	while (input[j] != NULL)
	{
		int index = (int)input[j];
		if (arr[index - 97] == 0 || lastIndex == index)
			arr[index - 97] = 1;
		else
			return 0;

		lastIndex = index;
		j++;
	}

	return 1;
}

int main()
{
	int num, result;
	char input[100];


	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", &input);
		result = checkGroup(input);
		if (result)
			groupCharNum++;
	}

	printf("%d\n", groupCharNum);

	return 0;
}

