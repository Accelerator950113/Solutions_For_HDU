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
int a[1024];
int ans;

int main() {

	cin >> n;
	while (cin >> n) {
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		sort(a, a + n);
		int md = (n + 1) / 2;
		ans = 0;
		for (int i = 1; i <= n; ++ i)
			ans += abs(a[i] - a[md]);
		cout << ans << endl;
	}

    return 0;
}
