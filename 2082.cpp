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
#define PI 3.14159265

using namespace std;

int T;
int a[32];
long long f[32][64];

double mo(double xx, double yy) {
	return sqrt(xx*xx + yy*yy);
}

int main() {

	cin >> T;
	while (T --) {
		for (int i = 1; i <= 26; ++ i)
			cin >> a[i];
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 1; i <= 26; ++ i)
			for (int j = 0; j <= a[i]; ++ j)
				for (int k = 50; k >= i*j; -- k)
					f[i][k] += f[i-1][k-i*j];
		long long ans = 0;
		for (int i = 1; i <= 50; ++ i)
			ans += f[26][i];
		cout << ans << endl;
	}

    return 0;
}
