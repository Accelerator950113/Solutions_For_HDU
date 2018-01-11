#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct node {
    int a[4];
    node () {}
    node (int x1,int x2,int x3,int x4) {
        a[0] = x1, a[1] = x2, a[2] = x3, a[3] = x4;
    }
    void tuozhan(int x,int y) {
        a[x] += y;
        if (a[x] == 10) a[x] = 1;
        if (a[x] == 0) a[x] = 9;
    }
    void swap(int x) {
        int tmp = a[x];
        a[x] = a[x + 1];
        a[x + 1] = tmp;
    }
};

queue < node > Q;
int dis[16][16][16][16];

int getdis(node a1) {
    return dis[a1.a[0]][a1.a[1]][a1.a[2]][a1.a[3]];
}

void setdis(node a1,int x) {
    dis[a1.a[0]][a1.a[1]][a1.a[2]][a1.a[3]] = x;
}

int work(int ss,int tt) {
    while (!Q.empty()) Q.pop();
    memset(dis,0x3f,sizeof(dis));
    Q.push(node(ss / 1000, (ss % 1000) / 100, (ss % 100) / 10, ss % 10));
    setdis(Q.front(),0);
    node cnt,nxt;
    while (!Q.empty()) {
        cnt = Q.front();
        Q.pop();
        for (int i = 0;i < 4;++ i)
            for (int j = -1;j < 2;j += 2) {
                nxt = cnt;
                nxt.tuozhan(i,j);
                if ((getdis(cnt) + 1) < getdis(nxt)) {
                    Q.push(nxt);
                    setdis(nxt,getdis(cnt) + 1);
                }
            }
        for (int i = 0;i < 3;++ i) {
            nxt = cnt;
            nxt.swap(i);
            if ((getdis(cnt) + 1) < getdis(nxt)) {
                Q.push(nxt);
                setdis(nxt,getdis(cnt) + 1);
            }
        }
    }
    return getdis(node(tt / 1000, (tt % 1000) / 100, (tt % 100) / 10, tt % 10));
}

int main() {

    int T,s,t;
    cin >> T;
    while (T --) {
        cin >> s >> t;
        cout << work(s,t) << endl;
    }
    
    return 0;
}
