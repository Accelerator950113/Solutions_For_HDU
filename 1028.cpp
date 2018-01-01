#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long f[512][512];
int n;
long long ans[512];

int main() {

    memset(f,0,sizeof(f));
    memset(ans,0,sizeof(ans));
    for (int i = 1;i <= 120;++ i) {
        f[i][i] = 1ll;
        for (int j = 1;j < i;++ j) 
            for (int k = 1;(k <= j) && (k <= (i - j));++ k)
                f[i][j] += f[i - j][k];
        for (int j = 1;j <= i;++ j)
            ans[i] += f[i][j];
    }

    while (scanf("%d",&n) == 1) 
        cout << ans[n] << endl;
    
    return 0;
}
