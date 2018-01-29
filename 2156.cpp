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

int n;
double ans;

int main() {

	while (cin >> n) {
		if (n == 0)
			break;
		ans = n;
		for (int i = n-1, j = 2; j <= n; -- i, ++ j)
			ans += 2.0*i / (double)j;
		printf("%.2lf\n", ans);
	}

    return 0;
}