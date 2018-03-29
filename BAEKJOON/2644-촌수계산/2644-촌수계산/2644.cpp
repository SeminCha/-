#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfFamily; // 입력되는 정점의 최댓값
int rear = 0, front = 0; // 전단과 후단을 나타내는 변수
int map[101][101], queue[101], visit[101]; // 인접 행렬과 큐와 방문 배열

void BFS(int v, int end)
{
	int i, count = 0;
	int start = v;

	visit[v] = 1; // 정점 v를 방문했다고 표시				 
	queue[rear++] = v; // 큐에 v를 삽입하고 후단을 1 증가시킴
	while (front < rear) // 후단이 전단과 같거나 작으면 루프 탈출
	{
		// 큐의 첫번째에 있는 데이터를 제외하고 제외된 값을 가져오며, 전단 1 증가
		v = queue[front++];
		for (i = 1; i <= numOfFamily; i++)
		{
			// 정점 v와 정점 i가 만나고, 정점 i를 방문하지 않은 상태일 경우
			if (map[v][i] == 1 && visit[i] != 1)
			{
				visit[i] = 1; // 정점 i를 방문했다고 표시							
				queue[rear++] = i; // 큐에 i를 삽입하고 후단을 1 증가시킴
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