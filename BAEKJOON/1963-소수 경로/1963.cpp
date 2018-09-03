#include<string>
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int MAX = 10000;
bool check[MAX + 1];
int dist[MAX + 1];
bool prime[MAX + 1];

int change(int num, int index, int digit) {
	if (index == 0 && digit == 0) {
		return -1;
	}
	string s = to_string(num);
	s[index] = digit + '0';
	return stoi(s);
}

int main() {
	int count, a, b;

	cin >> count;
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= 10000; j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = 0; i <= 10000; i++) {
		prime[i] = !prime[i];
	}
	for (int i = 0; i < count; i++) {
		cin >> a >> b;
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		queue<int> q;
		q.push(a);
		check[a] = true;
		dist[a] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int j = 0; j < 4; j++) {
				for (int k = 0; k <= 9; k++) {
					int next = change(now, j, k);
					if (next != -1) {
						if (prime[next] && check[next] == false) {
							q.push(next);
							check[next] = true;
							dist[next] = dist[now] + 1;
						}
					}
				}
			}
		}
		cout << dist[b] << '\n';
	}
}
