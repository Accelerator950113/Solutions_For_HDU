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

using namespace std;

int h, m, s;
int dh, dm;
int d;

int main() {

	cin >> h;
	while (cin >> h >> m >> s) {
		if (h >= 12) h -= 12;
		dh = 30*h*120 + (60*m+s);
		dm = 6*m*120 + s*12;
		d = abs(dh - dm);
		d = min(d, 360*120 - d);
		cout << d / 120 << endl;
	}

    return 0;
}
