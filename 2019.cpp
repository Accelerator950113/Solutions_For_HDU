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

int n, m;
int a[128];

int main() {

	while (cin >> n >> m) {
		if ((n == 0) && (m == 0)) break;
		for (int i = 0; i < n; ++ i)
			cin >> a[i];
		a[n ++] = m;
		sort(a, a + n);
		cout << a[0];
		for (int i = 1; i < n; ++ i)
			cout << ' ' << a[i];
		cout << endl;
	}

    return 0;
}
