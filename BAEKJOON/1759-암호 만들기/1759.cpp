#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool check(string pw) {
	int ja = 0, mo = 0;
	for (int i = 0; i < pw.length(); i++) {
		if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}

		if (mo >= 1 && ja >= 2) {
			return true;
		}
	}
	return false;
}

void go(int L, vector<char> &v, string pw, int i) {

	if (L == pw.length()) {
		if (check(pw)) {
			cout << pw << "\n";
		}
		return;
	}

	if (i == v.size()) {
		return;
	}

	go(L, v, pw + v[i], i + 1);
	go(L, v, pw, i + 1);
}

int main() {
	int L, C;
	scanf("%d %d", &L, &C);
	vector<char> v(C);
	getchar();

	for (int i = 0; i < C; i++) {
		scanf("%c", &v[i]);
		getchar();
	}

	sort(v.begin(), v.end());

	go(L,v,"",0);

	return 0;
}
