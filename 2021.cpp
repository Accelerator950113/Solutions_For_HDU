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

const int RMB[6] = {100, 50, 10, 5, 2, 1};
int n, ans;
int a[128];

int main() {

	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; ++ i)
			cin >> a[i];
		ans = 0;
		for (int i = 0; i < 6; ++ i)
			for (int j = 0; j < n; ++ j)
				ans += (a[j] / RMB[i]), a[j] %= RMB[i];
		cout << ans << endl;
	}

    return 0;
}
