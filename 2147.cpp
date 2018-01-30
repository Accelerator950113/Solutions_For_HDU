#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
bool f[2048][2048];

int main() {

    f[1][1] = false;
    for (int i = 2; i <= 2000; ++ i) 
        f[i][1] = !f[i-1][1], f[1][i] = !f[1][i-1];
    for (int i = 2; i <= 2000; ++ i)
        for (int j = 2; j <= 2000; ++ j)
            f[i][j] = !(f[i-1][j] && f[i][j-1] && f[i-1][j-1]);

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        cout << (f[n][m] ? "Wonderful!" : "What a pity!") << endl;
    }

    return 0;
}