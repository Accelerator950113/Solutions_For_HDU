#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[8];
int ans;

int main() {

    cin >> n;
    while (cin >> n) {
        a[0] = n / 2;
        n -= a[0];
        a[1] = n*2 / 3;
        n -= a[1];
        a[2] = n;
        ans = 0;
        for (int i = 0; i < 3; ++ i)
            ans += (a[i]+9) / 10;
        cout << ans << endl;
    }

    return 0;
}