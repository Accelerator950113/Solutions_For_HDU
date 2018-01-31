#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[128], b[128], c[128];

int main() {

    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        for (int i = 1; i <= n; ++ i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++ i) {
            b[i] = 1;
            for (int j = 1; j < i; ++ j)
                if (a[j] < a[i]) b[i] = max(b[i], b[j]+1);
        }
        for (int i = n; i > 0; -- i) {
            c[i] = 1;
            for (int j = i+1; j <= n; ++ j)
                if (a[i] > a[j]) c[i] = max(c[i], c[j]+1);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++ i)
            ans = max(ans, b[i]+c[i]-1);
        printf("%d\n", n-ans);
    }

    return 0;
}