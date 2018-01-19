#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int score[5][5] = {{0,-3,-4,-2,-1},{-3,5,-1,-2,-1},
						{-4,-1,5,-3,-2},{-2,-2,-3,5,-2},
						{-1,-1,-2,-2,5}};

int a[128],b[128];
int f[128][128][256];
int T,n,m,ans;
char ch;

int gi() {
	ch = getchar();
	while (!isalpha(ch))
		ch = getchar();
	if (ch == 'A') return 1;
	if (ch == 'C') return 2;
	if (ch == 'G') return 3;
	return 4;
}

int main() {

	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i = 1;i <= n;++ i)
			a[i] = gi();
		scanf("%d",&m);
		for (int i = 1;i <= m;++ i)
			b[i] = gi();
		memset(f,0xc0,sizeof(f));
		f[0][0][0] = 0;
		for (int i = 1;i <= n;++ i)
			f[i][0][i] = f[i-1][0][i-1] + score[a[i]][0];
		for (int i = 1;i <= m;++ i)
			f[0][i][i] = f[0][i-1][i-1] + score[0][b[i]];
		for (int i = 1;i <= n;++ i)
			for (int j = 1;j <= m;++ j)
				for (int k = max(i,j);k <= (i + j);++ k) {
					f[i][j][k] = max(f[i][j][k],f[i-1][j-1][k-1]+score[a[i]][b[j]]);
					f[i][j][k] = max(f[i][j][k],f[i-1][j][k-1]+score[a[i]][0]);
					f[i][j][k] = max(f[i][j][k],f[i][j-1][k-1]+score[0][b[j]]);
				}
		ans = -2147483648;
		for (int k = max(n,m);k <= (n+m);++ k)
			ans = max(ans,f[n][m][k]);
		printf("%d\n",ans);
	}
    
    return 0;
}
