#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define INF 1000000000000ll

using namespace std;

int n,m;
int a[1048576];
long long f[2][1048576][2];

long long getmax(long long x,long long y) {
    if (x > y) return x;
    return y;
}

int main() {

    while (scanf("%d%d",&m,&n) == 2) {
        for (int i = 1;i <= n;++ i) 
            scanf("%d",a + i);
        for (int i = 0;i <= m;++ i) {
            f[0][i][0] = -INF;
            f[0][i][1] = -INF;
            f[1][i][0] = -INF;
            f[1][i][1] = -INF;
        }
        f[0][0][0] = 0;
        for (int i = 1;i <= n;++ i) {
            f[i & 1][0][0] = f[(i + 1) & 1][0][0];
            for (int j = 1;j <= m;++ j) {
                f[i & 1][j][0] = getmax(f[(i + 1) & 1][j][0],f[(i + 1) & 1][j][1]);
                f[i & 1][j][1] = getmax(getmax(f[(i + 1) & 1][j - 1][0],f[(i + 1) & 1][j - 1][1]),f[(i + 1) & 1][j][1]) + (long long)a[i];
            }
        }
        cout << getmax(f[n & 1][m][0],f[n & 1][m][1]) << endl;
    }
    
    return 0;
}
