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
int a[8192], ans[128];
bool v[8192];

bool Dfs(int dep) {
    if (dep == n)
        return true;
    for (int i = 0; i < m; ++ i)
        if (!v[i]) {
            ans[dep] = a[i] - ans[0];
            break;
        }
    if (ans[dep] < ans[dep-1])
        return false;
    for (int i = 0; i < dep; ++ i) {
        int pos = (lower_bound(a, a+m, ans[i]+ans[dep]) - a);
        while (v[pos] && pos < m)
            pos ++;
        if ((pos == m) || (a[pos] != ans[i]+ans[dep]))
            return false;
        v[pos] = true;
    }
    return Dfs(dep+1);
}

bool Work() {
    memset(v, 0, sizeof(v));
    return Dfs(1);
}

int main() {
    
    while (scanf("%d", &n) == 1 && n != 0) {
        m = n * (n-1) / 2;
        for (int i = 0; i < m; ++ i)
            scanf("%d", &a[i]);
        sort(a, a+m);
        for (ans[0] = 1; ans[0] <= a[0]/2; ++ ans[0]) 
            if (Work()) 
                break;
        printf("%d", ans[0]);
        for (int i = 1; i < n; ++ i)
            printf(" %d", ans[i]);
        printf("\n");
    }

    return 0;
}