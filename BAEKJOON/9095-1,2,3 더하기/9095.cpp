#include <iostream>

using namespace std;

int go(int count, int sum, int goal) {
	if (sum > goal) {
		return 0;
	}

	if (sum == goal) {
		return 1;
	}

	int now = 0;
	for (int i = 1; i <= 3; i++) {
		now += go(count + 1, sum + i, goal);
	}

	return now;
}

int main() {
	int n, x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		printf("%d\n", go(0, 0, x));
	}

	return 0;
}
