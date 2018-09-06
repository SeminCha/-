#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10000;
bool check[101][101];;
bool arr[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	int m, n, k;
	pair<int, int> p;
	queue<pair<int, int>> q;
	vector<int> v;

	scanf("%d %d %d", &m, &n, &k);
	int x1, y1, x2, y2;

	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int j = x1; j < x2; j++) {
			for (int l = y1; l < y2; l++) {
				arr[j][l] = true;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		for (int l = 0; l < n; l++) {
			if (arr[l][j]==false) {
				memset(check, false, sizeof(check));
 				int count = 0;
				q.push(make_pair(l, j));
				check[l][j] = true;
				arr[l][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					count++;
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
							if (arr[nx][ny] == false && check[nx][ny] == false) {
								q.push(make_pair(nx, ny));
								arr[nx][ny] = true;
							}
							check[nx][ny] = true;

						}
					}
				}

				v.push_back(count);

			}
		}
	}

	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}

	return 0;
}
