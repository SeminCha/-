#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

char arr[21][21];
bool visited[26];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1,0,0 };
int R, C;

int go(int n) {

	int x = n / C;
	int y = n % C;

	visited[arr[x][y] - 65] = true;
	int count = 0;

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx >= 0 && cx < R && cy >= 0 && cy < C) {
			if (!visited[arr[cx][cy] - 65]) {
				int temp = go(cx*C + cy);
				if (count < temp) {
					count = temp;
				}
				visited[arr[cx][cy] - 65] = false;
			}
		}
	}

	return count+1;
}

int main() {

	string s;

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}

	int count = go(0);
	printf("%d\n", count);
	return 0;
}
