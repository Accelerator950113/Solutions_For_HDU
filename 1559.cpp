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
#define INF 2147483644

using namespace std;

int T, m, n, x, y;
int a[1024][1024];

int main() {
    
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%d%d", &m, &n, &x, &y);
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= m; ++ i)
            for (int j = 1; j <= n; ++ j) {
                scanf("%d", &a[i][j]);
                a[i][j] += (a[i-1][j] + a[i][j-1]);
                a[i][j] -= a[i-1][j-1];
            }
        int ans = -INF;
        for (int i = x; i <= m; ++ i)
            for (int j = y; j <= n; ++ j)
                ans = max(ans, a[i][j]-a[i-x][j]-a[i][j-y]+a[i-x][j-y]);
        printf("%d\n", ans);
    }

    return 0;
}