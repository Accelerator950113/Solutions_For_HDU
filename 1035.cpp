#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// North South West East
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

struct node {
	int x,y;
	node() {}
	node(int _x,int _y) {
		x = _x;
		y = _y;
	}
	void tuo(int ii) {
		x += dx[ii];
		y += dy[ii];
	}
};

queue < node > Q;

int dir[64][64];
int n,m,k;
int dis[64][64];
int ans,ans1,ans2;

int gi() {
	char ch = getchar();
	while (!isalpha(ch))
		ch = getchar();
	if (ch == 'N') return 0;
	if (ch == 'S') return 1;
	if (ch == 'W') return 2;
	return 3;
}

int main() {

	while (scanf("%d%d",&n,&m) == 2) {
		if ((n < 1) || (m < 1)) break;
		scanf("%d",&k);
		memset(dir,0xff,sizeof(dir));
		memset(dis,0xff,sizeof(dis));
		while (!Q.empty())
			Q.pop();
		ans = ans1 = ans2 = -1;
		Q.push(node(1,k));
		dis[1][k] = 0;
		for (int i = 1;i <= n;++ i)
			for (int j = 1;j <= m;++ j)
				dir[i][j] = gi();
		node cnt,nxt;
		while ((!Q.empty()) && (ans == -1) && (ans1 == -1)) {
			cnt = Q.front();
			Q.pop();
			nxt = cnt;
			nxt.tuo(dir[cnt.x][cnt.y]);
			if (dir[nxt.x][nxt.y] == -1) ans = dis[cnt.x][cnt.y] + 1;
			else {
				if (dis[nxt.x][nxt.y] != -1) {
					ans1 = dis[nxt.x][nxt.y];
					ans2 = dis[cnt.x][cnt.y] - ans1 + 1;
				}
				else {
					dis[nxt.x][nxt.y] = dis[cnt.x][cnt.y] + 1;
					Q.push(nxt);
				}
			}
		}
		if (ans == -1) printf("%d step(s) before a loop of %d step(s)\n",ans1,ans2);
		else printf("%d step(s) to exit\n",ans);
	} 

    return 0;
}
