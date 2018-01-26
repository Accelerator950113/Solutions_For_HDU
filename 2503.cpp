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

long long a, b, c, d;
long long fz, fm, chu;

long long gcd(long long x, long long y) {
	if (x%y == 0) return y;
	else return gcd(y, x%y);
}

int main() {

	cin >> a;
	while (cin >> a >> b >> c >> d) {
		fz = a * d + b * c;
		fm = b * d;
		chu = gcd(fz, fm);
		cout << fz/chu << " " << fm/chu << endl;
	}

    return 0;
}
