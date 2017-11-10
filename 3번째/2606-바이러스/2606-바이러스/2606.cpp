#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n; // �ԷµǴ� ������ �ִ�
int rear = 0, front = 0; // ���ܰ� �Ĵ��� ��Ÿ���� ����
int map[101][101], queue[101], visit[101]; // ���� ��İ� ť�� �湮 �迭

int BFS(int v)
{
	int i;
	int count = 0;

	visit[v] = 1; // ���� v�� �湮
	queue[rear++] = v; // ť�� v�� �����ϰ� �Ĵ��� 1 ����
	while (front < rear) // rear�� front�� ���ų� ������ ���� Ż��
	{
		// front 1 ����
		v = queue[front++];
		for (i = 1; i <= n; i++)
		{
			// ���� v�� ���� i�� ������, ���� i�� �湮���� ���� ������ ���
			if (map[v][i] == 1 && !visit[i])
			{
				visit[i] = 1; // ���� i�� �湮�ߴٰ� ǥ��			
				count++;
				queue[rear++] = i; // ť�� i�� �����ϰ� rear�� 1 ������Ŵ
			}
		}
	}

	return count;
}


int main()
{
	int relationNum = 0;
	int member1, member2, relations, parent, child;
	scanf("%d", &n);	
	scanf("%d", &relations);

	for (int i = 0; i < relations; i++)
	{
		scanf("%d %d", &parent, &child);
		map[parent][child] = map[child][parent] = 1;
	}

	int result = BFS(1);
	printf("%d\n", result);

	return 0;
}