#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

vector < int > G[128];
int N,M;
int F[128][128];
int C[128],V[128];
bool visited[128];

void solve(int now) {
    visited[now] = true;
    for (int i = C[now];i <= M;++ i) F[now][i] = V[now];
    for (int i = 0;i < G[now].size();++ i) 
        if (!visited[G[now][i]]) {
            solve(G[now][i]);
            for (int k = M;k >= C[now];-- k)
                for (int j = 1;j <= (k - C[now]);++ j)
                    if ((F[now][k - j] + F[G[now][i]][j]) > F[now][k]) {
                        F[now][k] = F[now][k - j] + F[G[now][i]][j];
                    }
        }
} 

int main() {

    while(scanf("%d%d",&N,&M) == 2) {
        if ((N == -1) && (M == -1)) break;
        for (int i = 1;i <= N;++ i) {
            scanf("%d%d",&C[i],&V[i]);
            C[i] = (C[i] + 19) / 20;
            G[i].clear();
        }
        int x,y;
        for (int i = 1;i < N;++ i) {
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if (M == 0) {
            printf("0\n");
            continue;
        }
        memset(F,0,sizeof(F));
        memset(visited,0,sizeof(visited));
        solve(1);
        printf("%d\n",F[1][M]);
    }
    
    return 0;
}
