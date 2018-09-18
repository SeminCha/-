#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
int d[1001];

int f(int x) {
	d[1] = 1;
	d[2] = 2;

	if (x < 3)
		return d[x];
	else {
		if (d[x] > 0)
			return d[x];
		else {
			int temp = f(x - 1) + f(x - 2);
			d[x] = temp % 10007;
			return d[x];
		}
	}
}

int main() {
	int x, count;
	scanf("%d", &x);
	count = f(x);
	printf("%d\n", count);
	return 0;
}
