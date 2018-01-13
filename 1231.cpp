#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int a[1048576];
int n,maxn,ms,md;

int main() {

    while (scanf("%d",&n) == 1) {
        if (n == 0) {
            break;
        }
        for (int i = 0;i < n;++ i)
            scanf("%d",a + i);
        int st = 0;
        int ts = 0;
        maxn = a[0];
        ms = 0;
        md = 0;
        for (int i = 0;i < n;++ i) {
            ts += a[i];
            if (ts > maxn) {
                maxn = ts;
                ms = st;
                md = i;
            }
            if (ts < 0) {
                st = i + 1;
                ts = 0;
            }
        }
        if (maxn < 0) printf("0 %d %d\n",a[0],a[n-1]);
        else printf("%d %d %d\n",maxn,a[ms],a[md]);
    }

    return 0;
}