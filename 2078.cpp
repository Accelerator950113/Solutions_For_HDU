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

int T;
int n, m;
int xx, yy;

int main() {

	cin >> T;
	while (cin >> n >> m) {
		yy = 100;
		while (n --) {
			cin >> xx;
			yy = min(yy, xx);
		}
		cout << (100-yy) * (100-yy) << endl;
	}

    return 0;
}
