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

const int RMB[5] = {1, 5, 10, 25, 50};

int n;
long long f[512][128];
long long ans[512];

int main() {

	memset(f, 0, sizeof(f));
	memset(ans, 0, sizeof(ans));
	f[0][0] = 1;
	for (int i = 0; i < 5; ++ i)
		for (int k = 1; k <= 100; ++ k)
			for (int j = RMB[i]; j <= 250; ++ j)
				f[j][k] += f[j - RMB[i]][k - 1];
	for (int i = 0; i <= 250; ++ i)
		for (int j = 0; j <= 100; ++ j)
			ans[i] += f[i][j];
	
	while (cin >> n)
		cout << ans[n] << endl;

    return 0;
}
