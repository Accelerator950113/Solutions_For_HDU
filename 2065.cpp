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

int cf(int x, unsigned long long y) {
	if (y == 0) return 1;
	if (y == 1) return (x % 100);
	int tmp = cf(x, y >> 1);
	tmp = (tmp * tmp) % 100;
	if (y & 1) tmp = (tmp * x) % 100;
	return tmp;
}

int main() {

	int T, cst;
	unsigned long long n;
	while (cin >> T) {
		if (T == 0) break;
		cst = 0;
		while (T --) { 
			cin >> n;
			cout << "Case " << ++cst << ": " << ((cf(4, n-1) + cf(2, n-1)) % 100) << endl;
		}
		cout << endl;
	}

    return 0;
}
