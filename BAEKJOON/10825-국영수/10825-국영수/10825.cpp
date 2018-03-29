#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student
{
	char name[11];
	int korean;
	int english;
	int math;
}Student;

Student array[100000];

int compare(const void *a, const void  *b)
{
	Student * first = (Student*)a;
	Student * second = (Student*)b;

	if (first->korean < second->korean)
		return 1;
	else if (first->korean > second->korean)
		return -1;
	else
	{
		if (first->english > second->english)
			return 1;
		else if (first->english < second->english)
			return -1;
		else
		{
			if (first->math < second->math)
				return 1;
			else if (first->math > second->math)
				return -1;
			else
			{
				return strcmp(first->name, second->name);
			}
		}
	}
	return 0;
}

int main()
{
	int numOfStd;

	scanf("%d", &numOfStd);

	for (int i = 0; i < numOfStd; i++)
	{
		scanf("%s %d %d %d", &array[i].name, &array[i].korean, &array[i].english, &array[i].math);
	}

	qsort(array, numOfStd, sizeof(Student), compare);

	for (int i = 0; i < numOfStd; i++)
	{
		printf("%s\n", array[i].name);
	}
	return 0;
}