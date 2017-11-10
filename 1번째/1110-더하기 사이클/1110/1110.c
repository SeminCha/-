#include <stdio.h>
#include <stdlib.h>

int main()
{
	int input=0, new=0, count = 0;
	int ten1, one1, ten2, one2, sum = 0;

	scanf("%d", &input);

	if (input < 0 || input > 99)
		return 0;

	new = input;

	do {
		if (new < 10)
		{
			ten1 = 0;
			one1 = new;
		}
		else
		{
			ten1 = new / 10;
			one1 = new % 10;
		}

		sum = ten1 + one1;

		if (sum < 10)
		{
			ten2 = 0;
			one2 = sum;
		}
		else
		{
			ten2 = sum / 10;
			one2 = sum % 10;
		}
				
		new = change(one1, one2);		
		count++;
	} while (input != new);
		
	printf("%d\n", count);
}

int change(int num1, int num2)
{	
	char s1[4];
	char s2[4];
	
	sprintf(s1, "%d", num1);
	sprintf(s2, "%d", num2);
	
	strcat(s1, s2);
	int result = (int)atoi(s1);
	return result;
}