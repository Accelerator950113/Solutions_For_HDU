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
bitset < 131072 > h;

int main() {

	h.reset();
	for (int i = 1; i <= 100000; ++ i)
		for (int j = i; j <= 100000; j += i)
			h[j] = h[j] ^ 1;

	while (cin >> n)
		cout << h[n] << endl;

    return 0;
}
