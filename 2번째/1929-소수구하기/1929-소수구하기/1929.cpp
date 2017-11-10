#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int findPrimeNum(int num)
{
	if (num == 1)
		return 0;
	
	for (int i = 2; i<=sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}

	return 1;
}


int main()
{
	int min, max, i;	

	scanf("%d %d", &min, &max);
	
	for (i = min; i < max; i++)
	{
		//소수가 맞다면 출력
		if (findPrimeNum(i) == 1)
			printf("%d\n", i);
	}
	
	return 0;
}
