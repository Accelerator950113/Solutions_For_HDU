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

int n;
long long c[64][64];
long long d[64];
long long ans[64];

int main() {

	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	memset(ans, 0, sizeof(ans));
	c[0][0] = 1;
	for (int i = 1; i <= 25; ++ i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++ j)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	d[0] = 1;
	d[1] = 0;
	d[2] = 1;
	for (int i = 3; i <= 25; ++ i)
		d[i] = (i-1) * (d[i-1]+d[i-2]);
	for (int i = 1; i <= 25; ++ i)
		for (int j = 0; j <= i/2; ++ j)
			ans[i] += (d[j] * c[i][j]);

	while (cin >> n) {
		if (n == 0) break;
		cout << ans[n] << endl;
	}

    return 0;
}
