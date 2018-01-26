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

int n, m, x;
set < int > S;

int main() {

	while (scanf("%d%d", &n, &m) != EOF) {
		if ((n == 0) && (m == 0)) break;
		S.clear();
		while (n --) {
			scanf("%d", &x);
			S.insert(x);
		}
		while (m --) {
			scanf("%d", &x);
			if (S.lower_bound(x) != S.end()) S.erase(x);
		}
		if (S.empty()) puts("NULL");
		else {
			for (set < int > :: iterator it = S.begin(); it != S.end(); ++ it)
				printf("%d ", *it);
			printf("\n");
		}
	}

    return 0;
}
