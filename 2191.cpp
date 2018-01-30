#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int n, m;
int p[128], h[128], c[128];
int f[128];

int main() {

    scanf("%d", &C);
    while (C --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++ i)
            scanf("%d%d%d", &p[i], &h[i], &c[i]);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; ++ i)
            for (int k = 1; k <= c[i]; ++ k)
                for (int j = n; j >= p[i]; -- j)
                    f[j] = max(f[j], f[j-p[i]] + h[i]);
        printf("%d\n", f[n]);
    }

    return 0;
}