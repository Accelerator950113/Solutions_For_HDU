#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int A[128],n,ans,cnt;

int main() {

    while(scanf("%d",&n) == 1) {
        if (n == 0) break;
        for (int i = 1;i <= n;++ i) scanf("%d",&A[i]);
        ans = 0, cnt = 0;
        for (int i = 1;i <= n;++ i) {
            if (A[i] > cnt) {
                ans = ans + (A[i] - cnt) * 6;
                cnt = A[i];
            }
            else {
                if (A[i] < cnt) {
                    ans = ans + (cnt - A[i]) * 4;
                    cnt = A[i];
                }
            }
            ans += 5;
        }
        printf("%d\n",ans);
    }
    
    
    return 0;
}
