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

int n;
char x;
int y;

int f(char x) {
	if (('a' <= x) && (x <= 'z'))
		return ((-1) * (x - 'a' + 1));
	return (x - 'A' + 1);
}

int main() {

	cin >> n;
	while (cin >> x >> y)
		cout << y + f(x) << endl;

    return 0;
}
