#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n,m;
int a[32768];

int main() {

    while (scanf("%d%d",&n,&m) == 2) {
        for (int i = 0;i < n+m;++ i)
            scanf("%d",&a[i]);
        sort(a,a + n+m);
        printf("%d",a[0]);
        for (int i = 1;i < n+m;++ i)
            if (a[i] != a[i-1]) printf(" %d",a[i]);
        printf("\n");
    }

    return 0;
}