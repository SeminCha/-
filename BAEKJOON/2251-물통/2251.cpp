#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <map>

using namespace std;
bool check[201][201];

int main() {
	int A, B, C, a, b, c, sum;
	queue<pair<int, int>> q;
	vector<int> v;
	scanf("%d %d %d", &A, &B, &C);
	a = 0, b = 0;
	c = C;
	q.push(make_pair(a, b));
	check[a][b] = true;
	v.push_back(c);

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		int x, y, z;
		a = now.first;
		b = now.second;
		c = C - a - b;

		//a->b

		if (a + b > B) {
			x = a + b - B;
			y = a + b - x;
		}
		else {
			x = 0;
			y = a + b;
		}
		z = C - x - y;

		if (!check[x][y]) {
			q.push(make_pair(x, y));
			check[x][y] = true;
			if (x == 0)
				v.push_back(z);
		}


		//a->c

		if (a + c > C) {
			x = a + c - C;
			z = a + c - x;
		}
		else {
			x = 0;
			z = a + c;
		}
		y = C - x - z;

		if (!check[x][y]) {
			q.push(make_pair(x, y));
			check[x][y] = true;
			if (x == 0) {
				v.push_back(z);
			}
		}


		//b->a

		if (b + a > A) {
			y = b + a - A;
			x = b + a - y;
		}
		else {
			y = 0;
			x = b + a;
		}
		z = C - x - y;

		if (!check[x][y]) {
			q.push(make_pair(x, y));
			check[x][y] = true;
			if (x == 0)
				v.push_back(z);
		}


		//b->c

		if (b + c > C) {
			y = b + c - C;
			z = b + c - y;
		}
		else {
			y = 0;
			z = b + c;
		}
		x = C - y - z;

		if (!check[x][y]) {
			q.push(make_pair(x, y));
			check[x][y] = true;
			if (x == 0)
				v.push_back(z);
		}


		//c->a

		if (c + a > A) {
			z = c + a - A;
			x = c + a - z;
		}
		else {
			z = 0;
			x = c + a;
		}
		y = C - x - z;

		if (!check[x][y]) {
			q.push(make_pair(x, y));
			check[x][y] = true;
			if (x == 0) {
				v.push_back(z);
			}
		}


		//c->b

		if (c + b > B) {
			z = c + b - B;
			y = c + b - z;
		}
		else {
			z = 0;
			y = c + b;
		}
		x = C - y - z;

		if (!check[x][y]) {
			q.push(make_pair(x, y));
			check[x][y] = true;
			if (x == 0) {
				v.push_back(z);
			}
		}

	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}
