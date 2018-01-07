#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[512][512];
int dis[512];
bool v[512];

int main() {

	while (scanf("%d",&n) == 1) {
		for (int i = 1;i <= n;++ i)
			for (int j = 1;j <= n;++ j)
				scanf("%d",&map[i][j]);
		int Q,x,y;
		scanf("%d",&Q);
		while (Q --) {
			scanf("%d%d",&x,&y);
			map[x][y] = 0;
			map[y][x] = 0;
		}
		memset(dis,0x3f,sizeof(dis));
		memset(v,0,sizeof(v));
		dis[1] = 0;
		for (int i = 1;i < n;++ i) {
			int minn = 2147483647, mid = 0;
			for (int j = 1;j <= n;++ j)
				if ((!v[j]) && (dis[j] < minn)) {
					minn = dis[j];
					mid = j;
				}
			v[mid] = true;
			for (int j = 1;j <= n;++ j)
				if ((!v[j]) && (dis[j] > map[mid][j]))
					dis[j] = map[mid][j];
		}
		int ans = 0;
		for (int i = 1;i <= n;++ i)
			ans += dis[i];
		printf("%d\n",ans);
	}
    
    return 0;
}
