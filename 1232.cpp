#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n,m,f[2048];
int ans,x,y;

int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

int main() {

	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		for (int i = 1;i <= n;++ i)
			f[i] = i;
		scanf("%d",&m);
		ans = n;
		while (m --) {
			scanf("%d%d",&x,&y);
			if (find(x) != find(y)) {
				ans --;
				f[find(x)] = find(y);
			}
		}
		printf("%d\n",ans - 1);
	}

    return 0;
}
