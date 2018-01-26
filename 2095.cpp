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
int ans, x;

int main() {

	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		ans = 0;
		while (n --) {
			scanf("%d", &x);
			ans ^= x;
		}
		printf("%d\n", ans);
	}

    return 0;
}
