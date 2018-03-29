#include <iomanip>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	vector<function<int(int, int)>> d;

	d.push_back([](int x, int y) {
		return x + y;
	});
	d.push_back([](int x, int y) {
		return x - y;
	});
	d.push_back([](int x, int y) {
		return x * y;
	});
	d.push_back([](int x, int y) {
		return x / y;
	});
	d.push_back([](int x, int y) {
		return x % y;
	});


	//cout << d[0](A, B) << '\n' << d[1](A, B) << '\n' << d[2](A, B) << '\n' << d[3](A, B) << '\n' << d[4](A, B) << '\n';
	//cout << d[0](A, B) << '\n';
	//cout << d.size();
	for (auto f : d) {
		cout << f(A, B) << '\n';
	}
}
