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

int minx, maxx, miny, maxy, x, y;

int main() {
    
    while (cin >> x >> y) {
        if (x == 0 && y == 0)
            break;
        minx = maxx = x;
        miny = maxy = y;
        while (x != 0 || y != 0) {
            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
            cin >> x >> y;
        }
        cout << minx << " " << miny << " " << maxx << " " << maxy << endl;
    }

    return 0;
}