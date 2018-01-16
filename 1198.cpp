#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

// Up Down Left Right
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
const int c[11][4] = {{1,0,1,0},{1,0,0,1},{0,1,1,0},{0,1,0,1},
                      {1,1,0,0},{0,0,1,1},{1,0,1,1},{1,1,1,0},
                      {0,1,1,1},{1,1,0,1},{1,1,1,1}};

int bh[64][64];
int f[8192];
int x[64][64];
int n,m,ans;

int get() {
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return (int)(ch - 'A');
}

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void merge(int x,int y) {
    if ((x == -1) || (y == -1)) return;
    if (find(x) != find(y)) {
        ans --;
        f[find(x)] = find(y);
    }
}

int main() {

    while (scanf("%d%d",&n,&m) == 2) {
        if ((n < 1) || (m < 1)) break;
        int tmp = 0;
        memset(bh,0xff,sizeof(bh));
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= m;++ j)
                bh[i][j] = ++ tmp;
        for (int i = 1;i <= n*m;++ i)
            f[i] = i;
        ans = n*m;
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= m;++ j)
                x[i][j] = get();
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= m;++ j) 
                for (int k = 0;k < 4;++ k)
                    if ((c[x[i][j]][k] == 1) && (c[x[i+dx[k]][j+dy[k]]][k^1] == 1)) merge(bh[i][j],bh[i+dx[k]][j+dy[k]]);
        printf("%d\n",ans);
    }

    return 0;
}