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
#define f(x) ((x) * (x))

using namespace std;

double d[256][256];

int main() {

	int x = 0, y = 0;
	d[0][0] = 0;
	while ((x != 101) || (y != 99)) {
		x ++, y --;
		if (y < 0) {
			d[0][x] = d[x-1][y+1] + sqrt(f(x-1) + f(y+1-x));
			y = x, x = 0;
		}
		else {
			d[x][y] = d[x-1][y+1] + sqrt(2);
		}
	}

	int xx, yy;
	cin >> x;
	while (cin >> x >> y >> xx >> yy) 
		printf("%.3lf\n", fabs(d[x][y] - d[xx][yy]));

    return 0;
}
