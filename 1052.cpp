#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int t[1024],k[1024];
int t_slow,t_fast,k_slow,k_fast;
int win,lose;

int main() {

    while ((scanf("%d",&n) == 1) && (n != 0)) {
        for (int i = 0;i < n;++ i)
            scanf("%d",&t[i]);
        for (int i = 0;i < n;++ i)
            scanf("%d",&k[i]);
        sort(t,t + n);
        sort(k,k + n);
        t_slow = 0, t_fast = n - 1;
        k_slow = 0, k_fast = n - 1;
        win = 0, lose = 0;
        while (t_slow <= t_fast) {
            if (t[t_slow] > k[k_slow]) {
                win ++;
                t_slow ++;
                k_slow ++;
                continue;
            }
            if (t[t_slow] < k[k_slow]) {
                lose ++;
                t_slow ++;
                k_fast --;
                continue;
            }
            if (t[t_fast] > k[k_fast]) {
                win ++;
                t_fast --;
                k_fast --;
                continue;
            }
            if (t[t_slow] < k[k_fast]) lose ++;
            t_slow ++;
            k_fast --;
        }
        printf("%d\n",(win - lose) * 200);
    }
    
    return 0;
}
