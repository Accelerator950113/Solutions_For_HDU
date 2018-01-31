#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define MOD 2008

using namespace std;

int n;
int l, a[32], b[32], c[32];
int len;
int lst[16384];
int ans[16384];
int tmp;

void dfs(int dep, int cnt) {
    if (dep > l) {
        lst[++ len] = cnt;
        return;
    }
    int tp = 1;
    for (int i = 0; i <= b[dep]; ++ i) {
        dfs(dep + 1, cnt * tp);
        tp *= a[dep];
    }
}

int cf(int x, int y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    int tp = cf(x, y / 2);
    tp = (tp * tp) % MOD;
    if (y & 1) tp = (tp * x) % MOD;
    return tp;
}

int main() {

    while (scanf("%d", &n) == 1) {
        if (n == 0) {
            printf("1\n");
            continue;
        }
        l = 0;
        for (int i = 2; i*i <= n; ++ i)
            if (n%i == 0) {
                a[++ l] = i;
                b[l] = 0;
                while (n%i == 0) {
                    n /= i;
                    b[l] ++;
                }
            }
        if (n > 1) 
            a[++ l] = n, b[l] = 1;
        len = 0;
        dfs(1, 1);
        ans[1] = 2;
        for (int i = 2; i <= len; ++ i) {
            ans[i] = cf(2, lst[i]);
            tmp = 0;
            for (int j = 1; j < i; ++ j)
                if (lst[i] % lst[j] == 0) tmp = (tmp + ans[j]) % MOD;
            ans[i] = (ans[i] - tmp + MOD) % MOD;
        }
        printf("%d\n", ans[len]);
    }

    return 0;
}