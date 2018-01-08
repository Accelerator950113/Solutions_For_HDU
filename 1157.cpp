#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int a[16384],n;

int main() {

    while (scanf("%d",&n) == 1) {
        for (int i = 1;i <= n;++ i)
            scanf("%d",&a[i]);
        sort(a + 1,a + n + 1);
        printf("%d\n",a[(n + 1) / 2]);
    }
    
    return 0;
}
