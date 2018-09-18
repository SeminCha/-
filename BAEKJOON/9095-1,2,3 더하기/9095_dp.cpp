#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
int d[11];

int f(int x) {
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	if (x < 3)
		return d[x];
	else {
		if (d[x] > 0)
			return d[x];
		else {
			d[x] = f(x - 1) + f(x - 2) + f(x-3);
			return d[x];
		}
	}
}

int main() {
	int x, count, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		count = f(x);
		printf("%d\n", count);
	}
	return 0;
}
