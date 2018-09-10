#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

bool prime[1005001];

bool isPalindrome(int n) {
	string s = to_string(n);

	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i - 1])
			return false;
	}

	return true;
}

int main() {

	long long n;
	cin >> n;
	prime[1] = true;
	for (long long i = 2; i <= 1005001; i++) {
		if (prime[i] == false) {
			for (long long j = i*i; j <= 1005001; j += i) {
				prime[j] = true;
			}
		}
	}

	int i = n;
	while (true) {	
		if (prime[i] == false) {
			if (isPalindrome(i) == true) {
				printf("%d\n", i);
				break;
			}
		}
		i++;
	}

	return 0;
}



