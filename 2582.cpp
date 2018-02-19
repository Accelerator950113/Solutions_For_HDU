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

int f[1048576];
long long ans[1048576];

int gcd(int x, int y) {
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

int main() {
    
    for (int i = 2; i <= 1000000; ++ i)
        f[i] = i;
    for (int i = 2; i <= 1000000; ++ i)
        if (f[i] == i) 
            for (int j = i+i; j <= 1000000; j += i)
                f[j] = gcd(f[j], i);

    ans[3] = (long long)f[3];
    for (int i = 4; i <= 1000000; ++ i)
        ans[i] = ans[i-1] + (long long)f[i];

    int n;
    while (cin >> n)
        cout << ans[n] << endl;

    return 0;
}