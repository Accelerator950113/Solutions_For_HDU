#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#define LL long long

using namespace std;

LL f[1024];
int a[1024];
int n;

int main() {

	while (true) {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 1;i <= n;++ i)
            scanf("%d",&a[i]);
        LL ans = a[1];
        for (int i = 1;i <= n;++ i) {
            f[i] = (LL)a[i];
            for (int j = 1;j < i;++ j)
                if ((a[i] > a[j]) && ((f[j] + (LL)a[i]) > f[i])) f[i] = f[j] + (LL)a[i];
            if (f[i] > ans) ans = f[i];
        }
        cout << ans << endl;
    }

    return 0;
}
