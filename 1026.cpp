#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

struct node {
    int x,y;
    node () {}
    node (int _x,int _y) {
        x = _x, y = _y;
    }
    void tuo(int i) {
        x += dx[i];
        y += dy[i];
    }
};

queue < node > Q;

int n,m;
int map[128][128];
int pre[128][128];
int dis[128][128];
char ch;

int gi() {
    ch = getchar();
    while ((!isdigit(ch)) && (ch != 'X') && (ch != '.'))
        ch = getchar();
    if (isdigit(ch)) return (ch - '0');
    if (ch == '.') return 0;
    return -1;
}

void OutImpossible() {
    puts("God please help our poor hero.");
    puts("FINISH");
}

void Output(node cnt,int t) {
    if (t == 0) return;
    node p = cnt;
    p.tuo(pre[cnt.x][cnt.y]);
    Output(p,t - 1 - map[cnt.x][cnt.y]);
    printf("%ds:(%d,%d)->(%d,%d)\n",t - map[cnt.x][cnt.y],p.x-1,p.y-1,cnt.x-1,cnt.y-1);
    for (int ii = 1;ii <= map[cnt.x][cnt.y];++ ii)
        printf("%ds:FIGHT AT (%d,%d)\n",t - map[cnt.x][cnt.y] + ii,cnt.x-1,cnt.y-1);
}

int main() {

    while (scanf("%d%d",&n,&m) == 2) {
        memset(map,0xff,sizeof(map));
        memset(dis,0x3f,sizeof(dis));
        memset(pre,0xff,sizeof(pre));
        while (!Q.empty()) Q.pop();
        for (int i = 1;i <= n;++ i) 
            for (int j = 1;j <= m;++ j)
                map[i][j] = gi();
        if ((map[1][1] == -1) || (map[n][m] == -1)) {
            OutImpossible();
            continue;
        }
        dis[1][1] = 0;
        Q.push(node(1,1));
        node cnt,nxt;
        while (!Q.empty()) {
            cnt = Q.front();
            Q.pop();
            for (int i = 0;i < 4;++ i) {
                nxt = cnt;
                nxt.tuo(i);
                if (map[nxt.x][nxt.y] != -1) {
                    if ((dis[cnt.x][cnt.y] + 1 + map[nxt.x][nxt.y]) < dis[nxt.x][nxt.y]) {
                        pre[nxt.x][nxt.y] = i^1;
                        dis[nxt.x][nxt.y] = dis[cnt.x][cnt.y] + 1 + map[nxt.x][nxt.y];
                        Q.push(nxt);
                    }
                }
            }   
        }
        if (dis[n][m] == dis[n + 1][m]) {
            OutImpossible();
            continue;
        }
        printf("It takes %d seconds to reach the target position, let me show you the way.\n",dis[n][m]);
        Output(node(n,m),dis[n][m]);
        puts("FINISH");
    }

    return 0;
}