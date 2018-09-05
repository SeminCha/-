#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	int n, pos;
	int init = 0;
	queue<int> q;
	map<int, int> dist;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &n);
		if (n == 0)
			n = 9;
		init = init * 10 + n;
	}

	q.push(init);
	dist[init] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		string s = to_string(now);
		pos = s.find('9');
		int x = pos / 3;
		int y = pos % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				int toPos = nx * 3 + ny;
				string nextS = s;
				swap(nextS[pos], nextS[toPos]);
				int next = stoi(nextS);
				if (dist.count(next) == 0) {
					q.push(next);
					dist[next] = dist[now] + 1;
				}
			}
		}
	}

	int result = 123456789;
	if (dist.count(result) == 0) {
		printf("-1");
	}
	else {
		printf("%d\n", dist[result]);
	}

	return 0;
}
