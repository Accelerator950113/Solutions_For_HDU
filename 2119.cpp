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

int g[128][128];
int n, m;
int link[128];
bool v[128];

bool dfs(int x) {
    if (v[x]) return false;
    v[x] = true;
    for (int i = 1; i <= m; ++ i)
        if (g[x][i] == 1 && (link[i] == -1 || dfs(link[i]))) {
            link[i] = x;
            return true;
        }
    return false;
}

int main() {
    
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= m; ++ j)
                scanf("%d", &g[i][j]);
        memset(link, 0xff, sizeof(link));
        int ans = 0;
        for (int i = 1; i <= n; ++ i) {
            memset(v, 0, sizeof(v));
            if (dfs(i))
                ans ++;
        }
        printf("%d\n", ans);
    }

    return 0;
}