#include <stdio.h>
#include <string.h>

int main()
{
	char roomNumber[8];
	int card[10] = { 0, };
	int numOfSet = 0;
	int numOf69Card = 0;	
	int i, length, index, temp;
	scanf("%s", &roomNumber);
	length = strlen(roomNumber);

	//�迭�� �� ���ȣ �ڸ������� ����
	for (i = 0; i < length; i++)
	{
		index = roomNumber[i] - 48;		
		//6 or 9ī�帻�� ������ ī���� ���
		if (index != 6 && index != 9)
		{
			card[index]++;
			if (card[index] > numOfSet)
				numOfSet = card[index];
		} 
		//6 or 9ī���� ���
		else
		{
			numOf69Card++;			
		}
	}

	//69ī�� ������ ¦���� ���
	if (numOf69Card % 2 == 0)	
		temp = numOf69Card / 2;	
	//69ī�� ������ Ȧ���� ���
	else	
		temp = numOf69Card / 2+1;
	
	//������ ī�尡 �ʿ��� ��Ʈ�������� Ŭ��쿡�� ������
	if (temp > numOfSet)
		numOfSet = temp;

	printf("%d\n", numOfSet);
	return 0;
}