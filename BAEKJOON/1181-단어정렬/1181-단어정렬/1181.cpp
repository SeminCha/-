#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//구조체로 단어와 단어길이 설정
typedef struct _data
{
	char word[51];
	int length;
}Data;

//단어길이 얻는 함수
int getWordLength(char word[])
{
	int length = strlen(word);
	return length;
}

//데이터 생성
Data initData(char word[])
{	
	Data data;

	data.length = getWordLength(word);
	strcpy(data.word, word);

	return data;
}

//사전 순 정렬
int compareDictOrder(char pivot[], char other[])
{
	int i = 0;

	while (pivot[i] != NULL)
	{
	    if((int)pivot[i] > (int)other[i])
		{
			return 1;
		}
		else if((int)pivot[i] < (int)other[i])
		{
			return 2;
		}		
		i++;
	}

	//아예 같은 문자인 경우
	return 0;
}

//삽입정렬
void InsertSort(Data a[], int n)
{
	Data insData, temp;
	int i, j;

	for (i = 1; i < n; i++)
	{
		insData = a[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (a[j].length > insData.length)
				a[j + 1] = a[j];
			else if (a[j].length == insData.length)
			{
				if (compareDictOrder(a[j].word, insData.word) == 1)
					a[j + 1] = a[j];				
				else
					break;
			}
			else
				break;
		}

		a[j + 1] = insData;
	}
}

int main()
{
	int num;
	char input[51];
	char lastWord[51];
	
	scanf("%d", &num);

	Data  * array = (Data *)malloc(sizeof(Data)*num);

	for (int i = 0; i < num; i++)
	{
		scanf("%s", &input);
		array[i] = initData(input);
	}
		
	InsertSort(array, num);

	strcpy(lastWord, "-");
	for (int i = 0; i < num; i++)
	{
		//중복확인
		if (strcmp(lastWord, array[i].word))
		{
			printf("%s", array[i].word);
			printf("\n");
			strcpy(lastWord, array[i].word);			
		}	
	}

	return 0;
}

