#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define D 10000
#define DD 100000000

using namespace std;

long long c[20];
int a[8],b[8];
int n,T;

void cf(int x) {
    if (x == 1) {
        a[1] = b[1];
        a[2] = b[2];
        a[3] = b[3];
        return;
    }
    cf(x / 2);
    memset(c,0,sizeof(c));
    for (int i = 1;i <= 5;++ i)
        for (int j = 1;j <= 5;++ j)
            c[i + j] += (long long)a[i] * (long long)a[j];
    if (x & 1) {
        for (int i = 1;i <= 15;++ i)
            c[i] *= (long long)n;
    }
    for (int i = 1;i <= 15;++ i) {
        c[i + 1] += (c[i] / D);
        c[i] %= D;
    }
    int t = 15;
    while (c[t] == 0) t --;
    memset(a,0,sizeof(a));
    for (int i = 5;i > 0;-- i)
        a[i] = (int)c[t --];
} 

int main() {

    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        b[1] = n % D;
        b[2] = (n % DD) / D;
        b[3] = n / DD;
        memset(a,0,sizeof(a));
        cf(n);
        int t = 5;
        while (a[t] == 0) t --;
        while (a[t] >= 10) a[t] /= 10;
        printf("%d\n",a[t]);
    }
    
    return 0;
}
