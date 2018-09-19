#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
long long d[101][10];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j > 0) {
				d[i][j] += d[i - 1][j - 1];
			}
			if (j < 9) {
				d[i][j] += d[i - 1][j + 1];
			}
			d[i][j] %= 1000000000;
		}
	}

	long long count = 0;
	for (int i = 0; i <= 9; i++) {
		count += d[n][i];
	}
	cout << count % 1000000000 << "\n";
	return 0;
}
