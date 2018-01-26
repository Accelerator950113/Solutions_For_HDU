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
#include <set>
#include <bitset>

using namespace std;

char s[2];
char h[128][128];
int n;
bool fir = true;

int main() {

	while (cin >> n >> s[0] >> s[1]) {
		if ((n / 2) & 1) swap(s[0], s[1]);
		if (fir) fir = false;
		else putchar('\n');
		if (n == 1) {
			printf("%c\n", s[0]);
			continue;
		}
		int now;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j) {
				now = min(min(i - 1, n - i), min(j - 1, n - j));
				h[i][j] = s[now & 1];
			}
		h[1][1] = h[1][n] = h[n][1] = h[n][n] = ' ';
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j)
				putchar(h[i][j]);
			putchar('\n');
		}
	}

    return 0;
}
