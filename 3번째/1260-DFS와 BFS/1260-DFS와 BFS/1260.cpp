#include <stdio.h>

int n; // �ԷµǴ� ������ �ִ�
int rear = 0, front = 0; // ���ܰ� �Ĵ��� ��Ÿ���� ����
int mapDFS[1001][1001], queue[1001], visitDFS[1001]; // ���� ��İ� ť�� �湮 �迭
int mapBFS[1001][1001], visitBFS[1001]; // ���� ��İ� ť�� �湮 �迭

void DFS(int v)
{
	int i;

	visitDFS[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��
	printf("%d ", v);
	for (i = 1; i <= n; i++)
	{
		// ���� v�� ���� i�� ����Ǿ���, ���� i�� �湮���� �ʾҴٸ�
		if (mapDFS[v][i] == 1 && !visitDFS[i])
		{			
			// ���� i���� �ٽ� DFS�� �����Ѵ�
			DFS(i);
		}
	}
}

void BFS(int v)
{
	int i;	

	visitBFS[v] = 1; // ���� v�� �湮
	queue[rear++] = v; // ť�� v�� �����ϰ� �Ĵ��� 1 ����
	printf("%d ", v);
	while (front < rear) // rear�� front�� ���ų� ������ ���� Ż��
	{
		// front 1 ����
		v = queue[front++];		
		for (i = 1; i <= n; i++)
		{
			// ���� v�� ���� i�� ������, ���� i�� �湮���� ���� ������ ���
			if (mapBFS[v][i] == 1 && !visitBFS[i])
			{
				visitBFS[i] = 1; // ���� i�� �湮�ߴٰ� ǥ��			
				printf("%d ", i);
				queue[rear++] = i; // ť�� i�� �����ϰ� rear�� 1 ������Ŵ
			}
		}
	}	
}



int main()
{
	int line, start;
	int member1, member2;
	scanf("%d %d %d", &n, &line, &start);

	for (int i = 1; i <= line; i++)
	{
		scanf("%d %d", &member1, &member2);
		mapDFS[member1][member2] = mapDFS[member2][member1] = 1;
		mapBFS[member1][member2] = mapBFS[member2][member1] = 1;
	}
	DFS(start);
	printf("\n");
	BFS(start);
}