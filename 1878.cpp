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

int d[1024], f[1024];
int n, m, x, y;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int Ola() {
    for (int i = 2; i <= n; ++ i)
        if (find(i) != find(1))
            return 0;
    for (int i = 1; i <= n; ++ i)
        if (d[i] & 1)
            return 0;
    return 1;
}

int main() {
    
    while (scanf("%d", &n) == 1 && n != 0) {
        scanf("%d", &m);
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; ++ i)
            f[i] = i;
        while (m --) {
            scanf("%d%d", &x, &y);
            d[x] ++;
            d[y] ++;
            f[find(x)] = find(y);
        }
        printf("%d\n", Ola());
    }

    return 0;
}