#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n,u,d;

int main() {

    while (cin >> n >> u >> d) {
        if (n == 0) break;
        int cnt = 0;
        for (int i = 1;i <= 2147483644;++ i) {
            if (i & 1) cnt += u;
            else cnt -= d;
            if (cnt >= n) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}