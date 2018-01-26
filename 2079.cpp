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
int n, k;
int a[32], b[32];
long long f[32][64];

int main() {

	cin >> T;
	while (T --) {
		cin >> n >> k;
		for (int i = 1; i <= k; ++ i)
			cin >> a[i] >> b[i];
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 1; i <= k; ++ i)
			for (int j = 0; j <= b[i]; ++ j)
				for (int v = n; v >= a[i]*j; -- v)
					f[i][v] += f[i-1][v-a[i]*j];
		cout << f[k][n] << endl;
	}

    return 0;
}
