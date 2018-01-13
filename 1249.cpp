#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int f[16384];
int t,n;

int main() {

    f[1] = 2;
    for (int i = 2;i <= 10000;++ i)
        f[i] = f[i - 1] + 6 * (i - 1);
    cin >> t;
    while (t --) {
        cin >> n;
        cout << f[n] << endl;
    }

    return 0;
}