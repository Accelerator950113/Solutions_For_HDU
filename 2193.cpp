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
#include <set>
#include <algorithm>

using namespace std;

int n;
int f[128];

int main() {
    
    ios::sync_with_stdio(false);
    
    f[0] = 1, f[1] = 2;
    for (int i = 2; i < 46; ++ i)
        f[i] = f[i-1] + f[i-2] + 1;

    while (cin >> n) {
        if (n == 0) 
            break;
        int ans = 0;
        while (f[ans] <= n)
            ans ++;
        cout << ans-1 << endl;
    }

    return 0;
}