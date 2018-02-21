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
    void read() {
        scanf("%d%d%d", &x, &y, &c);
    }
    friend bool operator <(const road &a1, const road &a2) {
        return (a1.c < a2.c);
    }
};

road r[32768];
int f[128];
int n, m;
int num, ans;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int main() {
    
    while (scanf("%d%d", &n, &m) == 2 && n != 0) {
        for (int i = 1; i <= m; ++ i)
            f[i] = i;
        for (int i = 0; i < n; ++ i)
            r[i].read();
        sort(r, r+n);
        num = ans = 0;
        for (int i = 0; i < n; ++ i)
            if (find(r[i].x) != find(r[i].y)) {
                num ++;
                ans += r[i].c;
                f[find(r[i].x)] = find(r[i].y);
            }
        if (num != m-1)
            printf("?\n");
        else 
            printf("%d\n", ans);
    }

    return 0;
}