#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct node {
    int y, d;
    node () {}
    node (int _y, int _d) {
        y = _y, d = _d;
    }
};

vector < node > g[MAXN];
int zd[MAXN], cd[MAXN], zdid[MAXN];
bool v[MAXN];
int ans[MAXN];
int n;
int x, y;

void dfs1(int cnt) {
    v[cnt] = true;
    zd[cnt] = cd[cnt] = 0;
    for (int i = 0; i < g[cnt].size(); ++ i)
        if (!v[g[cnt][i].y]) {
            dfs1(g[cnt][i].y);
            if (g[cnt][i].d + zd[g[cnt][i].y] > zd[cnt]) {
                cd[cnt] = max(cd[cnt], zd[cnt]);
                zd[cnt] = g[cnt][i].d + zd[g[cnt][i].y];
                zdid[cnt] = g[cnt][i].y;
            }
            else cd[cnt] = max(cd[cnt], g[cnt][i].d + zd[g[cnt][i].y]);
        }
}

void dfs2(int cnt, int len) {
    v[cnt] = true;
    ans[cnt] = max(len, zd[cnt]);
    for (int i = 0; i < g[cnt].size(); ++ i) 
        if (!v[g[cnt][i].y]) {
            if (zdid[cnt] != g[cnt][i].y)
                dfs2(g[cnt][i].y, ans[cnt] + g[cnt][i].d);
            else
                dfs2(g[cnt][i].y, max(len, cd[cnt]) + g[cnt][i].d);
        }
}

int main() {

    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; ++ i)
            g[i].clear();
        for (int i = 2; i <= n; ++ i) {
            scanf("%d%d", &x, &y);
            g[i].push_back(node(x, y));
            g[x].push_back(node(i, y));
        }
        memset(v, 0, sizeof(v));
        dfs1(1);
        memset(v, 0, sizeof(v));
        dfs2(1, 0);
        for (int i = 1; i <= n; ++ i)
            printf("%d\n", ans[i]);
    }

    return 0;
}