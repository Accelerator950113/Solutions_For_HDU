#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool map[8][8];
bool conf[32][32];
bool state[32];
int bh[8][8];
int x[32],y[32];
int n,ans,encode;

void dfs(int dep,int cnt) {
    if (dep > encode) {
        if (cnt > ans) ans = cnt;
        return;
    }
    bool can = true;
    for (int i = 1;i < dep;++ i)
        if ((state[i]) && (conf[i][dep])) can = false;
    if (can) {
        state[dep] = true;
        dfs(dep + 1,cnt + 1);
        state[dep] = false;
    }
    dfs(dep + 1,cnt);
}

int main() {

    while ((scanf("%d",&n) == 1) && (n != 0)) {
        memset(map,0,sizeof(map));
        memset(conf,0,sizeof(conf));
        encode = 0;
        char ch;
        for (int i = 1;i <= n;++ i) 
            for (int j = 1;j <= n;++ j) {
                ch = getchar();
                while ((ch != '.') && (ch != 'X'))
                    ch = getchar();
                if (ch == '.') {
                    bh[i][j] = ++ encode;
                    map[i][j] = true;
                    x[encode] = i;
                    y[encode] = j;
                }
            }
        for (int i = 1;i <= encode;++ i) {
            for (int j = x[i] - 1;map[j][y[i]];-- j)
                conf[i][bh[j][y[i]]] = true;
            for (int j = x[i] + 1;map[j][y[i]];++ j)
                conf[i][bh[j][y[i]]] = true;
            for (int j = y[i] - 1;map[x[i]][j];-- j)
                conf[i][bh[x[i]][j]] = true;
            for (int j = y[i] + 1;map[x[i]][j];++ j)
                conf[i][bh[x[i]][j]] = true;
        }
        ans = 0;
        memset(state,0,sizeof(state));
        dfs(1,0);
        printf("%d\n",ans);
    }
    
    return 0;
}
