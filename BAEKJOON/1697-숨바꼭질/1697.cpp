#include<string>
#include<iostream>
#include<queue>

using namespace std;
const int MAX = 200000;
bool check[MAX + 1];
int dist[MAX + 1];

int main() {
	int n, k;
	queue<int> q;
	cin >> n >> k;

	check[n] = true;
	q.push(n);
	dist[n] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x - 1 >= 0 && check[x - 1] == false) {
			q.push(x - 1);
			check[x - 1] = true;
			dist[x - 1] = dist[x] + 1;
			if (x - 1 == k)
				break;
		}

		if (x + 1 <= MAX && check[x + 1] == false) {
			q.push(x + 1);
			check[x + 1] = true;
			dist[x + 1] = dist[x] + 1;
			if (x + 1 == k)
				break;
		}

		if (2 * x <= MAX && check[2 * x] == false) {
			q.push(2 * x);
			check[2 * x] = true;
			dist[2 * x] = dist[x] + 1;
			if (2 * x == k)
				break;
		}
	}

	cout << dist[k];
	return 0;
}
