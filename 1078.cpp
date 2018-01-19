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

struct node {
	int x,y,p;
	node() {}
	void set(int _x,int _y,int _p) {
		x = _x;
		y = _y;
		p = _p;
	}
	friend bool operator <(const node &a1,const node &a2) {
		return (a1.p < a2.p);
	}
};

int n,k,m;
node A[16384];
int f[128][128];
int a[128][128];

int main() {

	while (scanf("%d%d",&n,&k) != EOF) {
		if (n < 1) break;
		memset(f,0xcf,sizeof(f));
		for (int i = 1;i <= n;++ i)
			for (int j = 1;j <= n;++ j) 
				scanf("%d",&a[i][j]);
		f[1][1] = a[1][1];
		m = 0;
		for (int i = 1;i <= n;++ i)
			for (int j = 1;j <= n;++ j) 
				if (a[i][j] > a[1][1]) A[++ m].set(i,j,a[i][j]);
		sort(A + 1,A + m + 1);
		int ans = f[1][1];
		for (int i = 1;i <= m;++ i) {
			for (int j = max(1,A[i].x - k);j <= min(n,A[i].x + k);++ j)
				if (a[j][A[i].y] < A[i].p) f[A[i].x][A[i].y] = max(f[A[i].x][A[i].y],f[j][A[i].y] + A[i].p);
			for (int j = max(1,A[i].y - k);j <= min(n,A[i].y + k);++ j)
				if (a[A[i].x][j] < A[i].p) f[A[i].x][A[i].y] = max(f[A[i].x][A[i].y],f[A[i].x][j] + A[i].p);
			ans = max(ans,f[A[i].x][A[i].y]);
		}
		printf("%d\n",ans);
	}
    
    return 0;
}
