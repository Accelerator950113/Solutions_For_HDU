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
int a, b;

int f(int x) {
	return (x % 100);
}

int main() {

	cin >> T;
	while (cin >> a >> b)
		cout << f(f(a) + f(b)) << endl;

    return 0;
}
