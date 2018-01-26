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

using namespace std;

int n;
long long f[64][4][4];
long long ans[64];

int main() {

	memset(f, 0, sizeof(f));
	f[2][1][1] = f[2][2][2] = f[2][3][3] = 0;
	f[2][1][2] = f[2][1][3] = 1;
	f[2][2][1] = f[2][2][3] = 1;
	f[2][3][1] = f[2][3][2] = 1;
	for (int i = 3; i <= 50; ++ i) 
		for (int j = 1; j <= 3; ++ j)
			for (int k = 1; k <= 3; ++ k)
				for (int l = 1; l <= 3; ++ l)
					if (k != l) f[i][j][k] += f[i-1][j][l];

	memset(ans, 0, sizeof(ans));
	ans[1] = 3;
	for (int i = 2; i <= 50; ++ i)
		for (int j = 1; j <= 3; ++ j)
			for (int k = 1; k <= 3; ++ k)
				if (j != k) ans[i] += f[i][j][k];

	while (cin >> n)
		cout << ans[n] << endl;

    return 0;
}
