#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>;

using namespace std;

char room[101][101];

int main() {
	int n;
	int garo = 0, sero = 0, count = 0;
	bool isCheck = true;

	char input;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			room[i][j] = input;			
		}
	}
	
	//가로자리검사
	for (int i = 0; i < n; i++) {		
		for (int j = 0; j < n; j++) {
			if (room[i][j] == '.') {
				isCheck = true;
				count++;
			}
			else {
				isCheck = false;
				if (count >= 2)
					garo++;
				count = 0;
			}
		}
		if (count >= 2) {
			garo++;			
		}
		count = 0;
	}

	//세로자리검사
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (room[i][j] == '.') {
				isCheck = true;
				count++;
			}
			else {
				isCheck = false;
				if (count >= 2)
					sero++;
				count = 0;
			}
		}
		if (count >= 2) {
			sero++;
		}
		count = 0;
	}

	printf("%d %d\n", garo, sero);

	return 0;
}


