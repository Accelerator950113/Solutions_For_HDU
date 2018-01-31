#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define MOD 2008

using namespace std;

long long f[32][8];
int n;

int main() {

    memset(f, 0, sizeof(f));
    f[1][7] = f[1][4] = f[1][1] = 1;
    for (int i = 2; i <= 30; ++ i) {
        f[i][7] = f[i-1][1] + f[i-1][4] + f[i-1][7];
        f[i][4] = f[i-1][7];
        f[i][1] = f[i-1][7];
    }

    cin >> n;
    while (cin >> n)
        cout << f[n][7] << endl;

    return 0;
}