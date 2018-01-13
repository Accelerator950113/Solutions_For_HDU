#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int a[1048576];
int n;

int main() {

    scanf("%d",&n);
    while (scanf("%d",&n) == 1) {
        for (int i = 0;i < n;++ i)
            scanf("%d",&a[i]);
        int mid = 0,r;
        for (int i = 1;i < n;++ i)
            if (a[i] > a[mid]) mid = i;
        r = a[mid];
        a[mid] = 0;
        for (int i = 0;i < n;++ i) {
            r -= a[i];
            if (r < 2) break;
        } 
        if (r < 2) puts("Yes");
        else puts("No");
    }

    return 0;
}