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

	//배열에 각 방번호 자릿수별로 저장
	for (i = 0; i < length; i++)
	{
		index = roomNumber[i] - 48;		
		//6 or 9카드말고 나머지 카드인 경우
		if (index != 6 && index != 9)
		{
			card[index]++;
			if (card[index] > numOfSet)
				numOfSet = card[index];
		} 
		//6 or 9카드일 경우
		else
		{
			numOf69Card++;			
		}
	}

	//69카드 갯수가 짝수인 경우
	if (numOf69Card % 2 == 0)	
		temp = numOf69Card / 2;	
	//69카드 갯수가 홀수인 경우
	else	
		temp = numOf69Card / 2+1;
	
	//나머지 카드가 필요한 세트개수보다 클경우에만 값변경
	if (temp > numOfSet)
		numOfSet = temp;

	printf("%d\n", numOfSet);
	return 0;
}