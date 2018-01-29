#include <iostream>
#include <algorithm>

using namespace std;

const int N = 505;

int l, n, m, len;
long long a[N], b[N], c[N];
long long sum[N * N];
int cst = 0;
int s, pos;
long long x;
long long *tp;
int i, j;

void readArr(long long *p, int Len) {
    for (i = 0; i < Len; ++ i)
        scanf("%lld", p + i);
}

bool check() {
    for (i = 0; i < m; ++ i) {
        tp = lower_bound(sum, sum+len, x-c[i]);
        pos = tp - sum;
        if ((pos != len) && (sum[pos]+c[i] == x)) 
            return true;
    }
    return false;
}

int main() {

    while (scanf("%d%d%d", &l, &n, &m) == 3) {
        readArr(a, l);
        readArr(b, n);
        readArr(c, m);
        len = 0;
        for (i = 0; i < l; ++ i)
            for (j = 0; j < n; ++ j)
                sum[len ++] = a[i]+b[j];
        sort(sum, sum+len);
        printf("Case %d:\n", ++cst);
        scanf("%d", &s);
        while (s --) {
            scanf("%lld", &x);
            if (check()) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}