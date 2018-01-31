#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool p[256];
long long f[256];
int n;

int main() {

    memset(p, 0xff, sizeof(p));
    p[0] = p[1] = false;
    for (int i = 2; i <= 150; ++ i)
        if (p[i])
            for (int j = i+i; j <= 150; j += i)
                p[j] = false;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 2; i <= 150; ++ i)
        if (p[i])
            for (int j = i; j <= 150; ++ j)
                f[j] += f[j-i];

    cin >> n;
    while (cin >> n)
        cout << f[n] << endl;

    return 0;
}