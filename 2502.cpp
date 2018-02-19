#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

long long c[32][32];
long long ans[32];

int main() {
    
    for (int i = 0; i < 20; ++ i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++ j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }

    for (int i = 1; i <= 20; ++ i) {
        ans[i] = 0;
        for (int j = 0; j < i; ++ j)
            ans[i] += ((long long)(j+1) * c[i-1][j]);
    }

    int T, n;
    cin >> T;
    while (T --) {
        cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}