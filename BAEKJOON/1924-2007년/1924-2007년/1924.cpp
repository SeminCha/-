#include<stdio.h>

int main()
{
	int month, day, result;
	int countDays = 0;

	char week[][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	scanf("%d %d", &month, &day);

	for (int i = 1; i < month; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			countDays += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			countDays += 30;
		else
			countDays += 28;
	}
	//�ش� �ޱ��� ��¥�� ���ϰ� �ű⼭ 7�� ������ ������ ����
	countDays += day;
	result = countDays % 7;
	printf("%s\n", week[result]);

	return 0;
}