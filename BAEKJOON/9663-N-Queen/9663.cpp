#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int arr[15][15];
int result = 0;

bool check(int n, int row, int col) {
	for (int i = 0; i < n; i++) {
		if (i == row)
			continue;
		if (arr[i][col])
			return false;
	}

	//대각선 왼쪽 위
	int r = row - 1;
	int c = col - 1;

	while (c >= 0 && r >= 0) {
		if (arr[r][c] == false) {
			r -= 1;
			c -= 1;
		}
		else {
			return false;
		}
	}

	//대각선 오른쪽 위
	r = row - 1;
	c = col + 1;

	while (c < n && r >= 0) {
		if (arr[r][c] == false) {
			r -= 1;
			c += 1;
		}
		else {
			return false;
		}
	}

	return true;
}

void go(int n, int row) {
	if (row == n) {
		result += 1;
	}


	for (int col = 0; col < n; col++) {
		arr[row][col] = true;
		if (check(n,row,col)) {
			go(n, row + 1);
		}
		arr[row][col] = false;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	go(n,0);
	printf("%d", result);
	return 0;
}
