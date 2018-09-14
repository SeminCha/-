#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

int n, s;
int num;
vector<int> v;

void go(int sum, int index) {

	int n = v.size();
	if (index == n) {
		if (sum == s)
			num+=1;

		return;
	}

	go(sum+v[index], index+1);
	go(sum, index+1);
}

int main() {

	int x;
	num = 0;
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}

	go(0, 0);
	if (s == 0) num -= 1;
	printf("%d\n", num);
	return 0;
}
