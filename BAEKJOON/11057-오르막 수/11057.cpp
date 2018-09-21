#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
long long d[1001][10];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			int k = 0;
			while (k <= j) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= 10007;
				k++;
			}
		}
	}

	int count = 0;
	for (int i = 0; i <= 9; i++) {
		count += d[n][i];
	}
	cout << count % 10007 << "\n";
	return 0;
}
