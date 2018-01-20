#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int t;
int day, d[16], a[2][32][32];

inline int jz(int x) {
	if (x > 3) return 3;
	if (x < 0) return 0;
	return x;
}

void print(int x) {
	if (x == 0) putchar('.');
	else if (x == 1) putchar('!');
	else if (x == 2) putchar('X');
	else putchar('#');
}

int main() {

	scanf("%d", &t);
	while (t --) {
		scanf("%d", &day);
		for (int i = 0; i < 16; ++ i)
			scanf("%d", &d[i]);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= 20; ++ i)
			for (int j = 1; j <= 20; ++ j)
				scanf("%d", &a[0][i][j]);
		for (int i = 1; i <= day; ++ i) 
			for (int j = 1; j <= 20; ++ j)
				for (int k = 1; k <= 20; ++ k) 
					a[i&1][j][k] = jz(a[(i+1)&1][j][k] + d[a[(i+1)&1][j][k] + a[(i+1)&1][j+1][k] + a[(i+1)&1][j][k+1] + a[(i+1)&1][j-1][k] + a[(i+1)&1][j][k-1]]);
		for (int i = 1; i <= 20; ++ i) {
			for (int j = 1; j <= 20; ++ j)
				print(a[day&1][i][j]);
			putchar('\n');
		}
		if (t) putchar('\n');
	}

    return 0;
}
