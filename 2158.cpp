#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int s[131072], num[131072], pos[131072], mark[131072];
int x, l, r, ans, q;

int main() {

    while (scanf("%d%d", &n, &m) == 2) {
        if (n == 0 && m == 0) 
            break;
        memset(mark, 0, sizeof(mark));
        memset(pos, 0xff, sizeof(pos));
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &s[i]);
            if (pos[s[i]] == -1)
                pos[s[i]] = i;
        }
        s[n] = n+1;
        for (int i = 1; i <= m; ++ i) {
            scanf("%d", &q);
            l = n, r = -1;
            for (int j = 0; j < q; ++ j) {
                scanf("%d", &x);
                num[x] = 0;
                mark[x] = i;
                r = max(r, pos[x]);
                l = min(l, pos[x]);
            }
            for (int j = l; j <= r; ++ j)
                num[s[j]] ++;
            ans = r - l + 1;
            while (r < n) {
                num[s[l]] --;
                if (num[s[l]] == 0) {
                    while (r+1 < n && s[r+1] != s[l]) 
                        num[s[++ r]] ++;
                    num[s[++ r]] ++;
                }
                l ++;
                while ((l <= r) && (mark[s[l]] != i))
                    l ++;
                if (r < n)
                    ans = min(ans, r-l+1);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}