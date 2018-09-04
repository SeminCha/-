#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 10000;
int dist[MAX + 1];
bool check[MAX + 1];
char how[MAX + 1];
int from[MAX + 1];

int main() {
	int count, a, b;
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d %d", &a, &b);
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(how, 0, sizeof(how));
		memset(from, 0, sizeof(from));
		queue<int> q;
		q.push(a);
		dist[a] = 0;
		check[a] = true;
		from[a] = -1;

		while (!q.empty()) {
			int now = q.front();
			int next;
			q.pop();

			//D
			next = (now * 2) % 10000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'D';
			}

			//S
			next = now - 1;
			if (next == -1) next = 9999;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'S';
			}

			//L
			next = (now % 1000) * 10 + (now / 1000);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'L';
			}

			//R
			next = (now / 10) + (now % 10)*1000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'R';
			}
		}

		int x = b;
		string result = "";
		while (a != x) {
			result = result+how[x];
			x = from[x];
		}
		reverse(result.begin(), result.end());
		cout << result << '\n';
	}
	return 0;
}
