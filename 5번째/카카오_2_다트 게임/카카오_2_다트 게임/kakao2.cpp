#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
	char input[10];
	int score[3];
	int count = -1;
	char op;

	printf("dartResult : ");
	scanf("%s", &input);
		
	for (int i = 0; i < strlen(input); i++)
	{
		//숫자인 경우
		if (isdigit(input[i]) != 0)
		{
			count++;
			
			//다음 자릿수도 숫자인 경우 (10인 경우)
			if (isdigit(input[i + 1]) != 0)
			{
				score[count] = 10;
			}
			//전 자릿수가 1이고 지금이 0인 경우
			else if(i>0&&isdigit(input[i - 1]) != 0)
			{
				continue;
			}
			else
			{
				//스코어 배열에 숫자저장
				score[count] = input[i] - 48;
			}			
		}
		//숫자 이외인 경우
		else
		{
			op = input[i];
			switch (op)
			{
			case 'S':
				score[count] = pow(score[count], 1);
				break;
			case 'D':
				score[count] = pow(score[count], 2);
				break;
			case 'T':
				score[count] = pow(score[count], 3);
				break;
			case '*':
				//첫 번째 기회에서 스타상이 나왔을 경우
				if (count == 0)
					score[count] = score[count] * 2;
				//나머지 기회에서 스타상이 나왔을 경우
				else
				{
					//바로 전의 점수 2배
					score[count - 1] = score[count - 1] * 2;
					//현재 점수 2배
					score[count] = score[count] * 2;
				}
				break;
			case '#':
				score[count] = score[count] * (-1);
				break;
			}
		}
	}

	printf("answer : %d\n", score[0] + score[1] + score[2]);
}