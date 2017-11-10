#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n; // 입력되는 정점의 최댓값
int rear = 0, front = 0; // 전단과 후단을 나타내는 변수
int map[101][101], queue[101], visit[101]; // 인접 행렬과 큐와 방문 배열

int BFS(int v)
{
	int i;
	int count = 0;

	visit[v] = 1; // 정점 v를 방문
	queue[rear++] = v; // 큐에 v를 삽입하고 후단을 1 증가
	while (front < rear) // rear가 front와 같거나 작으면 루프 탈출
	{
		// front 1 증가
		v = queue[front++];
		for (i = 1; i <= n; i++)
		{
			// 정점 v와 정점 i가 만나고, 정점 i를 방문하지 않은 상태일 경우
			if (map[v][i] == 1 && !visit[i])
			{
				visit[i] = 1; // 정점 i를 방문했다고 표시			
				count++;
				queue[rear++] = i; // 큐에 i를 삽입하고 rear를 1 증가시킴
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