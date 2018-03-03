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
int x, y;
int ans;
int f[256][256];

int main() {
    
    while (scanf("%d%d", &n, &m) == 2) {
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < n; ++ i)
            f[i][i] = 0;
        while (m --) {
            scanf("%d%d", &x, &y);
            if (x != y)
                f[x][y] = f[y][x] = 1;
        }
        for (int k = 0; k < n; ++ k)
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < n; ++ j)
                    f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
        ans = 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j)
                ans = max(ans, f[i][j]);
        if (ans > 7)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}