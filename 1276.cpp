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

int pre[8192], nxt[8192];
int tot, cnt;
int n;

void del(int x) {
	pre[nxt[x]] = pre[x];
	nxt[pre[x]] = nxt[x];
}

void baoShu(int MOD) {
	for (int i = nxt[0], j = 1; i <= n; i = nxt[i], j = (j+1)%MOD)
		if (j == 0) {
			del(i);
			tot --;
		}
}

int main() {

	cin >> n;
	while (cin >> n) {
		for (int i = 1; i <= n; ++ i)
			nxt[i] = i+1, pre[i] = i-1;
		nxt[0] = 1, nxt[n+1] = n+1;
		pre[0] = 0, pre[n+1] = n;
		tot = n;
		while (tot > 3) {
			baoShu(2);
			if (tot <= 3) break;
			baoShu(3);
		}
		printf("%d", nxt[0]);
		for (int i = nxt[nxt[0]]; i <= n; i = nxt[i])
			printf(" %d", i);
		printf("\n");
	}

    return 0;
}