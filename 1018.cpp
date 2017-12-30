#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int N,n;
double ans;

int main() {

	scanf("%d",&N);
    while (N --) {
        ans = 0;
        scanf("%d",&n);
        for (int i = 1;i <= n;++ i) 
            ans = ans + log10(i);
        printf("%d\n",(int)ceil(ans));
    }
    
    return 0;
}
