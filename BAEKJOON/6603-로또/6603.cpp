#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

int arr[6];

void go(vector<int> &v, int n, int index) {
	
	if (n == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = index; i < v.size(); i++) {
		arr[n] = v[i];
		go(v, n + 1, i+1);
		arr[n] = 0;
	}

	return;
}

int main() {

	int k, n;

	while (true) {
		scanf("%d", &k);
		if (k == 0)
			break;
		vector<int> v;
		for (int i = 0; i < k; i++) {
			scanf("%d", &n);
			v.push_back(n);
		}
		go(v,0,0);
		printf("\n");
	}

	return 0;
}
