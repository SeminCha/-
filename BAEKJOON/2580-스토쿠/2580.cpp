#include <iostream>

using namespace std;

int arr[9][9];
bool rowCheck[9][10];
bool colCheck[9][10];
bool squareCheck[9][9];

int getSquareIdx(int x, int y) {
	int dx = x / 3;
	int dy = y / 3;

	return dx * 3 + dy;
}

void go(int n) {
	if (n == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	int x = n / 9;
	int y = n % 9;

	if (arr[x][y] != 0) {
		go(n + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (!rowCheck[x][i] && !colCheck[y][i] && !squareCheck[getSquareIdx(x, y)][i]) {
				arr[x][y] = i;
				rowCheck[x][i] = colCheck[y][i] = squareCheck[getSquareIdx(x, y)][i] = true;
				go(n + 1);
				arr[x][y] = 0;
				rowCheck[x][i] = colCheck[y][i] = squareCheck[getSquareIdx(x, y)][i] = false;
			}
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0) {
				rowCheck[i][arr[i][j]] = true;
				colCheck[j][arr[i][j]] = true;
				squareCheck[getSquareIdx(i, j)][arr[i][j]] = true;
			}
		}
	}
	go(0);

	return 0;
}
