#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int c1,c2,c5;

int solve() {
    if (c1 == 0) return 1;
    if (c2 == 0) {
        if (c1 < 2) return 2;
        if (c1 < 3) return 3;
        if (c1 < 4) return 4;
    }
    if (c2 == 1) {
        if (c1 < 2) return 4;
    }
    return ((5 * c5) + (2 * c2) + c1 + 1);
}

int main() {

    while (cin >> c1 >> c2 >> c5) {
        if ((c1 == 0) && (c2 == 0) && (c5 == 0)) break;
        cout << solve() << endl;
    }
    
    return 0;
}
