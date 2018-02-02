#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
int a[1048576];

int main() {
    
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; ++ i)
            scanf("%d", a+i);
        sort(a, a+n);
        reverse(a, a+n);
        printf("%d", a[0]);
        for (int i = 1; i < m; ++ i)
            printf(" %d", a[i]);
        printf("\n");
    }

    return 0;
}