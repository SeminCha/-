#include <stdio.h>
#include <string.h> 

int cacheSize;

int nextIndex(int pos)
{
	if (pos == cacheSize)
		return 0;
	else
		return (pos + 1)%cacheSize;
}

int main()
{	
	char cache[30][20];
	char input[20];
	int time = 0;
	int front = 0, rear = 0;
	bool isExist;

	printf("캐쉬크기 입력 : ");
	scanf("%d", &cacheSize);

	printf("도시이름 입력 : ");
	while (true)
	{
		scanf("%s", &input);
	
		if (!strcmp(input, "끝"))
			break;

		isExist = false;
		for (int i = 1; i <= cacheSize; i++)
		{
			if (input == cache[i])
			{
				isExist = true;
				break;
			}			
		}

		// 캐쉬에 있을 경우
		if (isExist)
		{
			time += 1;
		}
		// 캐쉬에 없을 경우
		else
		{
			// 큐가 꽉 찼을 경우
			if (nextIndex(rear) == front)
			{
				//LRU규칙에 의한 삭제
				front++;
				strcpy(input, cache[rear]);
			}
			else
			{
				rear = nextIndex(rear);
				strcpy(input, cache[rear]);
			}
			time += 5;
		}		
	}

	printf("실행시간 : %d\n", time);
	return 0;
}