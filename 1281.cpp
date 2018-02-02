#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
    point() {}
};

point p[16384];
bool h[16384];
int n, m, k, maxans, gs;
bool g[128][128];
int link[128];
bool v[128];
bool impo[128][128];
int cst = 0;

bool dfs(int x) {
    if (v[x]) return false;
    v[x] = true;
    for (int i = 1; i <= m; ++ i)
        if (g[x][i] && (link[i] == -1 || dfs(link[i]))) {
            link[i] = x;
            return true;
        } 
    return false;
}

int Hungary() {
    int ts = 0;
    memset(link, 0xff, sizeof(link));
    for (int i = 1; i <= n; ++ i) {
        memset(v, 0, sizeof(v));
        if (dfs(i))
            ts ++;
    }
    return ts;
}

int main() {
    
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        memset(g, 0, sizeof(g));
        int x, y;
        for (int i = 1; i <= k; ++ i) {
            scanf("%d%d", &p[i].x, &p[i].y);
            g[p[i].x][p[i].y] = true;
        }
        maxans = Hungary();
        memset(impo, 0, sizeof(impo));
        for (int i = 1; i <= m; ++ i)
            if (link[i] != -1)
                impo[link[i]][i] = true;
        for (int i = 1; i <= k; ++ i)
            if (impo[p[i].x][p[i].y]) h[i] = true;
            else h[i] = false;
        gs = 0;
        for (int i = 1; i <= k; ++ i)
            if (h[i]) {
                g[p[i].x][p[i].y] = false;
                if (Hungary() != maxans) 
                    gs ++;
                g[p[i].x][p[i].y] = true;
            }
        printf("Board %d have %d important blanks for %d chessmen.\n", ++cst, gs, maxans);
    }

    return 0;
}