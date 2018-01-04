#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int a[131072],b[131072];
int n;

bool check() {
    for (int i = 1;i < n;++ i)
        if (a[i] != a[0]) return false;
    return true;
}

int main() {

    while ((scanf("%d",&n) == 1) && (n != 0)) {
        for (int i = 0;i < n;++ i) 
            scanf("%d",&a[i]);
        int t = 0, p;
        while (!check()) {
            t ++;
            for (int i = 0;i < n;++ i) {
                b[i] = (a[(i + 1) % n] / 2) + (a[i] / 2);
                if (b[i] & 1) b[i] ++;
            }
            for (int i = 0;i < n;++ i)
                a[i] = b[i];
        }
        printf("%d %d\n",t,a[0]);
    }
    
    return 0;
}
