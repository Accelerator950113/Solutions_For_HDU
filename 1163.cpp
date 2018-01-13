#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int cf(int x,int y) {
    if (y == 1) return (x % 9);
    int tmp = cf(x,y / 2);
    tmp = (tmp * tmp) % 9;
    if (y & 1) tmp = (tmp * x) % 9;
    return tmp;
}

int main() {

    int n;
    while (scanf("%d",&n) == 1) {
        if (n == 0) break;
        int ans = cf(n,n);
        if (ans == 0) ans = 9;
        printf("%d\n",ans);
    }

    return 0;
}