#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <sstream>

using namespace std;

int n;
long long ans[65536];

int main() {

    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for (int cent = 1; cent <= 3; ++ cent)
        for (int i = cent; i <= 32768; ++ i)
            ans[i] += ans[i - cent];

    while (cin >> n)
        cout << ans[n] << endl;

    return 0;
}