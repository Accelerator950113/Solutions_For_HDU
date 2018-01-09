#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define getmax(x,y) ((x > y) ? (x) : (y))

using namespace std;

int n,ans,x;
int s[512][512];

int main() {

    while (scanf("%d",&n) == 1) {
        memset(s,0,sizeof(s));
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= n;++ j) {
                scanf("%d",&x);
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
            }
        ans = -2147483647;
        for (int si = 1;si <= n;++ si)
            for (int sj = 1;sj <= n;++ sj)
                for (int ei = si;ei <= n;++ ei)
                    for (int ej = sj;ej <= n;++ ej)
                        ans = getmax(ans,s[ei][ej] - s[si - 1][ej] - s[ei][sj - 1] + s[si - 1][sj - 1]);
        printf("%d\n",ans);
    }
    
    return 0;
}
