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

long long f[32];

int main() {
    
    f[0] = f[1] = 1;
    for (int i = 2; i <= 30; ++ i)
        f[i] = f[i-1] + f[i-2] + f[i-2];

    int T, n;
    cin >> T;
    while (T --) {
        cin >> n;
        cout << f[n] << endl;
    }

    return 0;
}