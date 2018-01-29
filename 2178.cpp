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

int n;

int main() {

	cin >> n;
	while (cin >> n)
		cout << ((1 << n) - 1) << endl;

    return 0;
}