#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long d[100001][3];
long long a[100001][2];

long long max3(long long a, long long b, long long c) {
	return max(max(a, b), c);
}

int main() {
	long long T, n, maxPoint;
	cin >> T;

	while (T>0) {
		T--;
		maxPoint = 0;
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[j][i];
			}
		}

		d[0][0] = 0;
		d[0][1] = 0;
		d[0][2] = 0;
		for (long long i = 1; i <= n; i++) {
			d[i][0] = max3(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][1];
		}

		for (long long i = 1; i <= n; i++) {
			long long temp = max3(d[i][0], d[i][1], d[i][2]);
			maxPoint = max(temp, maxPoint);
		}

		cout << maxPoint << "\n";

	}

	return 0;
}
