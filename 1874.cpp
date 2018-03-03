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

int n, m;
int x, y, c;
int s, t;
int f[256][256];

int main() {
    
    while (scanf("%d%d", &n, &m) == 2) {
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < n; ++ i)
            f[i][i] = 0;
        while (m --) {
            scanf("%d%d%d", &x, &y, &c);
            if (c < f[x][y])
                f[x][y] = f[y][x] = c;
        }
        for (int k = 0; k < n; ++ k)
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < n; ++ j)
                    f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
        scanf("%d%d", &s, &t);
        if (f[s][t] == f[n][n])
            printf("-1\n");
        else
            printf("%d\n", f[s][t]);
    }

    return 0;
}