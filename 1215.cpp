#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int t;
int l;
int a[16384],b[16384];
int n;
long long ans;

int main() {

    cin >> t;
    while (t --) {
        int tp;
        cin >> n;
        tp = n;
        l = 0;
        for (int i = 2;i*i <= n;++ i) 
            if (n%i == 0) {
                a[++ l] = i;
                b[l] = 0;
                while (n%i == 0) {
                    n /= i;
                    b[l] ++;
                }
            }
        if (n != 1) {
            a[++ l] = n;
            b[l] = 1;
        }
        ans = 1;
        long long tans;
        int tmp;
        for (int i = 1;i <= l;++ i) {
            tans = 1;
            tmp = 1;
            for (int j = 0;j < b[i];++ j) {
                tmp *= a[i];
                tans += (long long)tmp;
            }
            ans *= tans;
        }
        ans -= (long long)tp;
        cout << ans << endl;
    }

    return 0;
}