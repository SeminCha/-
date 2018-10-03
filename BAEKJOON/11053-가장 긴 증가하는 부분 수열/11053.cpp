#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	vector<int> v;
	vector<int> d(1001);
	int n,a;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < v.size(); i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && d[i] < d[j]+1) {
				d[i] = d[j] + 1;
			}
		}
	}

	cout << *max_element(d.begin(), d.end()) << "\n";

	return 0;
}
