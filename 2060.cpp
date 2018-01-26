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

int n, a, b;

int main() {

	cin >> n;
	while (cin >> n >> a >> b) {
		if (n > 6) a += ((n-6)*8+27);
		else a += ((15-n)*n/2);
		if (a >= b) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

    return 0;
}
