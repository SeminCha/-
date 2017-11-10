#include <stdio.h>

int n; // 입력되는 정점의 최댓값
int rear = 0, front = 0; // 전단과 후단을 나타내는 변수
int mapDFS[1001][1001], queue[1001], visitDFS[1001]; // 인접 행렬과 큐와 방문 배열
int mapBFS[1001][1001], visitBFS[1001]; // 인접 행렬과 큐와 방문 배열

void DFS(int v)
{
	int i;

	visitDFS[v] = 1; // 정점 v를 방문했다고 표시
	printf("%d ", v);
	for (i = 1; i <= n; i++)
	{
		// 정점 v와 정점 i가 연결되었고, 정점 i를 방문하지 않았다면
		if (mapDFS[v][i] == 1 && !visitDFS[i])
		{			
			// 정점 i에서 다시 DFS를 시작한다
			DFS(i);
		}
	}
}

void BFS(int v)
{
	int i;	

	visitBFS[v] = 1; // 정점 v를 방문
	queue[rear++] = v; // 큐에 v를 삽입하고 후단을 1 증가
	printf("%d ", v);
	while (front < rear) // rear가 front와 같거나 작으면 루프 탈출
	{
		// front 1 증가
		v = queue[front++];		
		for (i = 1; i <= n; i++)
		{
			// 정점 v와 정점 i가 만나고, 정점 i를 방문하지 않은 상태일 경우
			if (mapBFS[v][i] == 1 && !visitBFS[i])
			{
				visitBFS[i] = 1; // 정점 i를 방문했다고 표시			
				printf("%d ", i);
				queue[rear++] = i; // 큐에 i를 삽입하고 rear를 1 증가시킴
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