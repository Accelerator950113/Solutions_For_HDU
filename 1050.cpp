#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct node {
    int x,d;
    node () {}
    node (int _x,int _d) {
        x = _x;
        d = _d;
    }
    friend bool operator <(const node &a1,const node &a2) {
        if (a1.x == a2.x) return (a1.d > a2.d);
        return (a1.x < a2.x);
    }
};

int T;
node A[1024];
int l,n;
int x,y;

int main() {

    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        l = 0;
        while (n --) {
            scanf("%d%d",&x,&y);
            x = (x + 1) / 2;
            y = (y + 1) / 2;
            if (x > y) {
            	A[++ l] = node(y,1);
            	A[++ l] = node(x,-1);
            }
            else {
            	A[++ l] = node(x,1);
            	A[++ l] = node(y,-1);
            }
        }
        sort(A + 1,A + l + 1);
        int ans = 0,ts = 0;
        for (int i = 1;i <= l;++ i) {
            ts += A[i].d;
            if (ts > ans) ans = ts;
        }
        cout << ans*10 << endl;
    }

    return 0;
}