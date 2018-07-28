#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;

int calculate(vector<int> &a) {
	int sum = 0;
	
	for (int i = 1; i < a.size(); i++) {
		int x = a[i - 1] - a[i];
		if (x < 0) {
			x = -x;
		}
		sum += x;
	}

	return sum;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a.begin(), a.end());
	int ans = 0;
	do {
		int temp = calculate(a);
		ans = max(ans, temp);
	} while (next_permutation(a.begin(), a.end()));
	
	printf("%d\n", ans);
	return 0;
}