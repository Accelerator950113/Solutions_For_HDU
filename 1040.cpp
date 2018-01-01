#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int n,a[1024];

int main() {

    scanf("%d",&T);
    while (T --) {
        scanf("%d",&n);
        for (int i = 0;i < n;++ i) 
            scanf("%d",a + i);
        sort(a,a + n);
        printf("%d",a[0]);
        for (int i = 1;i < n;++ i) 
            printf(" %d",a[i]);
        printf("\n");
    }
    
    return 0;
}
