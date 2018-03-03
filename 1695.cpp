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

int T;
int a, b, c, d, k;
int m;
int p[131072];
bool v[131072];
int f[131072];

long long solve(int n1, int n2) {
    long long ts = 0;
    for (int i = 1; i <= n1; ++ i)
        ts += (((long long)(n1/i) * (long long)(n2/i)) * f[i]);
    return ts;
}

int main() {
    
    m = 0;
    memset(v, 0, sizeof(v));
    f[1] = 1;
    for (int i = 2; i <= 100010; ++ i) {
        if (!v[i]) {
            v[i] = true;
            p[m ++] = i;
            f[i] = -1;
        }
        for (int j = 0; j < m; ++ j) {
            if (i*p[j] > 100010)
                break;
            v[i*p[j]] = true;
            if (i%p[j] == 0) {
                f[i*p[j]] = 0;
                break;
            }
            else
                f[i*p[j]] = -f[i];
        }
    }

    scanf("%d", &T);
    for (int cst = 1; cst <= T; ++ cst) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        printf("Case %d: ", cst);
        if (k == 0) {
            cout << "0" << endl;
            continue;
        }
        b /= k;
        d /= k;
        if (b > d)
            swap(b, d);
        cout << solve(b, d) - solve(b, b) / 2 << endl;
    }

    return 0;
}