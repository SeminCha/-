#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long d[10001][3];
long long a[10001];

int main() {
	long long n, maxDrink;

	maxDrink = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[0][0] = 0;
	d[0][1] = 0;
	d[0][2] = 0;
	for (long long i = 1; i <= n; i++) {
		d[i][0] = max(max(d[i - 1][0], d[i-1][1]), d[i - 1][2]);
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	for (long long i = 1; i <= n; i++) {
		long long temp = max(max(d[i][0], d[i][1]), d[i][2]);
		maxDrink = max(temp, maxDrink);
	}

	cout << maxDrink << "\n";
	return 0;
}
