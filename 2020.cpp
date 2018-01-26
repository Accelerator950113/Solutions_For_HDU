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

bool cmp(int x, int y) {
	return (abs(x) > abs(y));
}

int main() {

	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; ++ i)
			cin >> a[i];
		sort(a, a + n, cmp);
		cout << a[0];
		for (int i = 1; i < n; ++ i)
			cout << ' ' << a[i];
		cout << endl;
	}

    return 0;
}
