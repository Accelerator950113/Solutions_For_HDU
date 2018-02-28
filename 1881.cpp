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

struct party {
    int h, l, t;
    void readin() {
        scanf("%d%d%d", &h, &l, &t);
    }
    friend bool operator <(const party &a1, const party &a2) {
        return (a1.t < a2.t);
    }
};

int n;
party a[64];
int f[16384];
int maxw;

int main() {
    
    while (scanf("%d", &n) == 1 && n > 0) {
        maxw = 0;
        for (int i = 0; i < n; ++ i) {
            a[i].readin();
            maxw = max(maxw, a[i].t);
        }
        sort(a, a+n);
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++ i)
            for (int j = a[i].t; j >= a[i].l; -- j)
                f[j] = max(f[j], f[j - a[i].l] + a[i].h);
        int ans = f[0];
        for (int i = 1; i <= maxw; ++ i)
            ans = max(ans, f[i]);
        printf("%d\n", ans);
    }

    return 0;
}