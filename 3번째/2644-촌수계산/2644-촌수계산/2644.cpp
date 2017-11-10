#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfFamily; // �ԷµǴ� ������ �ִ�
int rear = 0, front = 0; // ���ܰ� �Ĵ��� ��Ÿ���� ����
int map[101][101], queue[101], visit[101]; // ���� ��İ� ť�� �湮 �迭

void BFS(int v, int end)
{
	int i, count = 0;
	int start = v;

	visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��				 
	queue[rear++] = v; // ť�� v�� �����ϰ� �Ĵ��� 1 ������Ŵ
	while (front < rear) // �Ĵ��� ���ܰ� ���ų� ������ ���� Ż��
	{
		// ť�� ù��°�� �ִ� �����͸� �����ϰ� ���ܵ� ���� ��������, ���� 1 ����
		v = queue[front++];
		for (i = 1; i <= numOfFamily; i++)
		{
			// ���� v�� ���� i�� ������, ���� i�� �湮���� ���� ������ ���
			if (map[v][i] == 1 && visit[i] != 1)
			{
				visit[i] = 1; // ���� i�� �湮�ߴٰ� ǥ��							
				queue[rear++] = i; // ť�� i�� �����ϰ� �Ĵ��� 1 ������Ŵ
				if (i == end)
				{
					printf("%d\n", count + 1);
					return;
				}
			}
		}
		count++;
	}

	printf("%d\n", -1);
}


int main()
{
	int relationNum = 0;
	int member1, member2, relations, parent, child;

	scanf("%d", &numOfFamily);
	scanf("%d %d", &member1, &member2);
	scanf("%d", &relations);

	for (int i = 1; i <= relations; i++)
	{
		scanf("%d %d", &parent, &child);
		map[parent][child] = 1;
		map[child][parent] = 1;
	}

	if (member1 == member2)
		printf("%d\n", 0);
	else
		BFS(member1, member2);

	return 0;
}