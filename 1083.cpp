#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int T;
int N,P;
int m,x;
vector < int > G[512];
bool v[512];
int link[512];

bool dfs(int x) {
    if (v[x]) return false;
    v[x] = true;
    for (int i = 0;i < G[x].size();++ i) {
        if ((link[G[x][i]] == -1) || (dfs(link[G[x][i]]))) {
            link[G[x][i]] = x;
            return true;
        }
    }
    return false;
}

int main() {

    scanf("%d",&T);
    while (T --) {
        scanf("%d%d",&P,&N);
        for (int i = 1;i <= P;++ i) {
            G[i].clear();
            scanf("%d",&m);
            while (m --) {
                scanf("%d",&x);
                G[i].push_back(x + P);
            }
        }
        memset(link,0xff,sizeof(link));
        int ans = 0;
        for (int i = 1;i <= P;++ i) {
            memset(v,0,sizeof(v));
            if (dfs(i)) ans ++;
        }
        if (ans == P) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
