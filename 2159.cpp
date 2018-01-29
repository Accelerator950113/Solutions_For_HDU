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
#include <sstream>

using namespace std;

int f[128][128];
int n, m, k, s;
int a[128], b[128];
int ans;

int main() {

	while (cin >> n >> m >> k >> s) {
		for (int i = 1; i <= k; ++ i)
			cin >> a[i] >> b[i];
		memset(f, 0x3f, sizeof(f));
		f[0][0] = 0;
		for (int i = 1; i <= k; ++ i)
			for (int j = 1; j <= s; ++ j)
				for (int l = a[i]; l <= n+25; ++ l)
					f[j][l] = min(f[j][l], f[j-1][l-a[i]]+b[i]);
		ans = f[s+1][n];
		for (int i = 0; i <= s; ++ i)
			for (int j = n; j <= n+25; ++ j)
				ans = min(ans, f[i][j]);
		if (ans > m)
			ans = -1;
		else 
			ans = m - ans;
		cout << ans << endl;
	}

    return 0;
}