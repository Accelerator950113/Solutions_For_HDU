#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define getmax(x,y) ((x > y) ? (x) : (y))

using namespace std;

int H[131072][16];
int maxt,x,y,n;

int main() {

	while ((scanf("%d",&n) == 1) && (n > 0)) {
		memset(H,0,sizeof(H));
		maxt = 0;
		for (int i = 1;i <= n;++ i) {
			scanf("%d%d",&x,&y);
			H[y][x] ++;
			maxt = getmax(maxt,y);
		}
		for (int i = maxt - 1;i >= 0;-- i) {
			H[i][0] += getmax(H[i + 1][0],H[i + 1][1]);
			for (int j = 1;j < 10;++ j)
				H[i][j] += getmax(getmax(H[i + 1][j - 1],H[i + 1][j]),H[i + 1][j + 1]);
			H[i][10] += getmax(H[i + 1][10],H[i + 1][9]);
		}
		printf("%d\n",H[0][5]);
	}

    return 0;
}
