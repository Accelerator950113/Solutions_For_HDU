#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct dami {
    int p, w;
    void readin() {
        scanf("%d%d", &p, &w);
    }
    friend bool operator <(const dami &a1, const dami &a2) {
        return (a1.p<a2.p);
    }
    int tot() {
        return p*w;
    }
};

int n, m;
dami A[1024];
double ans;

int main() {

    scanf("%d", &n);
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= m; ++ i)
            A[i].readin();
        sort(A + 1, A + m + 1);
        ans = 0;
        for (int i = 1; i <= m; ++ i)
            if (n >= A[i].tot()) {
                n -= A[i].tot();
                ans += (double)A[i].w;
            }
            else {
                ans += (double)n / (double)A[i].p;
                break;
            }
        printf("%.2lf\n", ans);
    }

    return 0;
}