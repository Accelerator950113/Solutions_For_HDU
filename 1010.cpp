#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

struct point {
    int x,y;
    point() {}
    point(int xx,int yy) {
        x = xx, y = yy;
    }
};

int n,m,T,sx,sy,tx,ty,size;
bool flag;
bool map[16][16];
int dis[16][16];
queue < point > Q;
point pre,now;

point go(point a,int x) {
    return point(a.x + dx[x],a.y + dy[x]);
}

bool isunit(char x) {
    return ((x == '.') || (x == 'X') || (x == 'S') || (x == 'D'));
}

int getunit() {
    char ch = getchar();
    while (!isunit(ch)) ch = getchar();
    if (ch == 'X') return -1;
    if (ch == '.') return 0;
    if (ch == 'S') return 1;
    if (ch == 'D') return 2;
    return -2;
}

long long getpos(int x,int y) {
    return (1ll << ((x - 1) * n + (y - 1)));
}

void solve(point cnt,int step,long long state) {
    if ((flag) || (step > T)) return;
    if (step == T) {
        if ((cnt.x == tx) && (cnt.y == ty)) {
            flag = true;
            return;
        }
        return;
    }
    if ((step + dis[cnt.x][cnt.y]) > T) return;
    point np;
    for (int i = 0;i < 4;++ i) {
        np = go(cnt,i);
        if ((map[np.x][np.y]) && ((state & getpos(np.x,np.y)) == 0)) {
            solve(np,step + 1,state | getpos(np.x,np.y));
        }
    }
}

int main() {

    while(scanf("%d%d%d",&m,&n,&T) == 3) {
        if ((n == 0) && (m == 0) && (T == 0)) break;
        memset(map,0,sizeof(map));
        flag = false;
        sx = sy = 0;
        tx = ty = 0;
        size = 2;
        int tp;
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= m;++ j) {
                tp = getunit();
                if (tp >= 0) map[i][j] = true;
                if (tp == 1) {
                    sx = i;
                    sy = j;
                }
                if (tp == 2) {
                    tx = i;
                    ty = j;
                }
            }
        memset(dis,0x3f,sizeof(dis));
        while (!Q.empty()) Q.pop();
        Q.push(point(tx,ty));
        dis[tx][ty] = 0;
        while (!Q.empty()) {
            pre = Q.front();
            Q.pop();
            for (int i = 0;i < 4;++ i) {
                now = go(pre,i);
                if ((map[now.x][now.y]) && ((dis[pre.x][pre.y] + 1) < dis[now.x][now.y])) {
                    dis[now.x][now.y] = dis[pre.x][pre.y] + 1;
                    if ((now.x != sx) || (now.y != sy)) {
                        Q.push(now);
                        size ++;
                    }
                }
            }
        }

        if ((T < size) && (T > dis[sx][sy]) && (((T - dis[sx][sy]) % 2) == 0)) solve(point(sx,sy),0,getpos(sx,sy));
        else flag = (T == dis[sx][sy]);

        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    
    
    return 0;
}
