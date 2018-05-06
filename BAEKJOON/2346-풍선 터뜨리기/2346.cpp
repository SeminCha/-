#include<list>
#include<string>
#include<iostream>

using namespace std;

int main() {
	list<pair<int, int>> l;
	int n, num;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		l.push_back({ i, num });
	}

	auto iter = l.begin();
	auto temp = iter;
	int order, move;

	for (int i = 0; i < n - 1; i++) {
		order = iter->first;
		move = iter->second;
		temp = iter;
		if (move < 0)
			move = -move;

		cout << order << " ";
		if (iter->second > 0) {
			temp++;
			if (temp == l.end())
				temp = l.begin();
			l.erase(iter);
			iter = temp;
			for (int i = 1; i < move; i++) {
				iter++;
				if (iter == l.end()) {
					iter = l.begin();
				}
			}
		}
		else {
			if (temp == l.begin())
				temp = l.end();
			temp--;
			l.erase(iter);
			iter = temp;
			for (int i = 1; i < move; i++) {
				if (iter == l.begin()) {
					iter = l.end();
				}
				iter--;
			}
		}
	}
	cout << l.front().first << '\n';
}