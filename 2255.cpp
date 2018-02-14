#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>
#define INF 2147483644

using namespace std;

int n;
int w[512][512];
bool vx[512],vy[512];
int lx[512],ly[512],link[512];

bool Dfs(int u) {
    if (vx[u])
        return false;
    vx[u] = true;
    for (int v = 1; v <= n; ++ v)
        if (!vy[v] && lx[u]+ly[v] == w[u][v]) {
            vy[v] = true;
            if (link[v] == -1 || Dfs(link[v])) {
                link[v] = u;
                return true;
            }
        }
    return false;
}

bool Find(int x) {
    memset(vx, 0, sizeof(vx));
    memset(vy, 0, sizeof(vy));
    return Dfs(x);
}

int main() {
    
    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j)
                scanf("%d", &w[i][j]);
        for (int i = 1; i <= n; ++ i) {
            lx[i] = w[i][1], ly[i] = 0;
            for (int j = 2; j <= n; ++ j)
                lx[i] = max(lx[i], w[i][j]);
        }
        memset(link, 0xff, sizeof(link));
        for (int i = 1; i <= n; ++ i) 
            while (!Find(i)) {
                int d = INF;
                for (int j = 1; j <= n; ++ j)
                    if (vx[j])
                        for (int k = 1; k <= n; ++ k)
                            if (!vy[k])
                                d = min(d, lx[j]+ly[k]-w[j][k]);
                for (int j = 1; j <= n; ++ j)
                    if (vx[j])
                        lx[j] -= d;
                for (int j = 1; j <= n; ++ j)
                    if (vy[j])
                        ly[j] += d;
            }
        int ans = 0;
        for (int i = 1; i <= n; ++ i)
            ans += w[link[i]][i];
        printf("%d\n", ans);
    }

    return 0;
}