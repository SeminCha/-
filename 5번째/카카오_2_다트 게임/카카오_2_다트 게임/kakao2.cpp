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
		//������ ���
		if (isdigit(input[i]) != 0)
		{
			count++;
			
			//���� �ڸ����� ������ ��� (10�� ���)
			if (isdigit(input[i + 1]) != 0)
			{
				score[count] = 10;
			}
			//�� �ڸ����� 1�̰� ������ 0�� ���
			else if(i>0&&isdigit(input[i - 1]) != 0)
			{
				continue;
			}
			else
			{
				//���ھ� �迭�� ��������
				score[count] = input[i] - 48;
			}			
		}
		//���� �̿��� ���
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
				//ù ��° ��ȸ���� ��Ÿ���� ������ ���
				if (count == 0)
					score[count] = score[count] * 2;
				//������ ��ȸ���� ��Ÿ���� ������ ���
				else
				{
					//�ٷ� ���� ���� 2��
					score[count - 1] = score[count - 1] * 2;
					//���� ���� 2��
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