#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int t;
int n,m;
int f[2048];

int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

int main() {

	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;++ i)
			f[i] = i;
		int ans = n;
		int x,y;
		for (int j = 1;j <= m;++ j) {
			scanf("%d%d",&x,&y);
			if (find(x) != find(y)) {
				ans --;
				f[find(x)] = find(y);
			}
		}
		printf("%d\n",ans);
	}

    return 0;
}
