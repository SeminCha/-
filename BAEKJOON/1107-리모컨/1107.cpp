#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;
bool broken[10];

int possible(int n) {
	if (n == 0) {
		if (broken[n]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (n > 0) {
		int x = n % 10;
		if (broken[x]) {
			return 0;
		} 
		len++;
		n = n / 10;
	}
	return len;
}
int main() {

	int n, count;
	
	scanf("%d %d", &n, &count);
	
	for (int i = 0; i < count; i++) {
		int num;
		scanf("%d", &num);
		broken[num] = true;
	}

	int ans = n - 100;
	if (ans < 0) {
		ans = -ans;
	}

	for (int i = 0; i < 1000000; i++) {
		int channel = i;
		int len = possible(channel);
		if (len > 0) {
			int press = n - channel;
			if (press < 0) {
				press = -press;
			}
			if (ans > press + len) {
				ans = press + len;
			}
		}
	}

	printf("%d\n", ans);
	 	
	return 0;
}