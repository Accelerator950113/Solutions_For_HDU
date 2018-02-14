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

using namespace std;

const int dx[6] = {1,-1,0,0,0,0};
const int dy[6] = {0,0,1,-1,0,0};
const int dz[6] = {0,0,0,0,1,-1};

struct node {
    int x,y,z;
    node() {}
    node(int _x, int _y, int _z) {
        x = _x, y = _y, z = _z;
    }
    node trans(int i) {
        return node(x+dx[i], y+dy[i], z+dz[i]);
    }
};

queue < node > Q;
bool m[64][64][64];
int dist[64][64][64];
int T, A, B, C, K, x;

int main() {
    
    scanf("%d", &K);
    while (K --) {
        scanf("%d%d%d%d", &A, &B, &C, &T);
        memset(m, 0, sizeof(m));
        for (int i = 1; i <= A; ++ i)
            for (int j = 1; j <= B; ++ j)
                for (int k = 1; k <= C; ++ k) {
                    scanf("%d", &x);
                    if (x == 0) 
                        m[i][j][k] = true;
                }
        memset(dist, 0x3f, sizeof(dist));
        dist[1][1][1] = 0;
        while (!Q.empty())
            Q.pop();
        Q.push(node(1, 1, 1));
        node cnt, nxt;
        while (!Q.empty()) {
            cnt = Q.front();
            Q.pop();
            for (int i = 0; i < 6; ++ i) {
                nxt = cnt.trans(i);
                if ((m[nxt.x][nxt.y][nxt.z]) && (dist[cnt.x][cnt.y][cnt.z]+1 < dist[nxt.x][nxt.y][nxt.z])) {
                    dist[nxt.x][nxt.y][nxt.z] = dist[cnt.x][cnt.y][cnt.z]+1;
                    Q.push(nxt);
                }
            }
        }
        if (dist[A][B][C] <= T) 
            printf("%d\n", dist[A][B][C]);
        else
            printf("-1\n");
    }    

    return 0;
}