#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
	deque<int> d;

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;

		if (line == "push_front") {
			cin >> num;
			d.push_front(num);
		}
		else if (line == "push_back") {
			cin >> num;
			d.push_back(num);
		}
		else if (line == "pop_front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (line == "pop_back") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (line == "size") {
			cout << d.size() << '\n';
		}
		else if (line == "empty") {
			cout << d.empty() << '\n';
		}
		else if (line == "front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
			}
		}
		else if (line == "back") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
			}
		}
	}
}
