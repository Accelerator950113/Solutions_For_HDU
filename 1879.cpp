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

struct road {
    int x, y, c;
    road() {}
    road(int _x, int _y, int _c) {
        x = _x, y = _y, c = _c;
    }
    friend bool operator <(const road &a1, const road &a2) {
        return (a1.c < a2.c);
    }
};

road r[16384];
int f[128];
int n, m;
int x, y, c, fl;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int main() {
    
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 1; i <= n; ++ i)
            f[i] = i;
        m = 0;
        for (int i = 0; i < n*(n-1)/2; ++ i) {
            scanf("%d%d%d%d", &x, &y, &c, &fl);
            if (fl == 1) 
                f[find(x)] = find(y);
            else
                r[m ++] = road(x, y, c);
        }
        sort(r, r+m);
        int ans = 0;
        for (int i = 0; i < m; ++ i)
            if (find(r[i].x) != find(r[i].y)) {
                f[find(r[i].x)] = find(r[i].y);
                ans += r[i].c;
            }
        printf("%d\n", ans);
    }

    return 0;
}