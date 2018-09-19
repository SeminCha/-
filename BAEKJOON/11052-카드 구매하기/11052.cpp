#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
int d[1001];
int p[1001];

int f(int x) {
	if (x == 0)
		return 0;

	if (d[x] > 0)
		return d[x];

	else {
		for (int i = 1; i <= x; i++) {
			d[x] = max(f(x - i) + p[i], d[x]);
		}
		return d[x];
	}
}

int main() {
	int x, count, n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	printf("%d\n", f(n));
	return 0;
}
