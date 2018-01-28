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

bool p[16384];
int n;

int main() {

	memset(p, 0xff, sizeof(p));
	for (int i = 2; i <= 10000; ++ i)
		if (p[i]) 
			for (int j = i+i; j <= 10000; j += i)
				p[j] = false;
	while (cin >> n)
		for (int i = n/2, j = n/2; i > 0; -- i, ++ j)
			if (p[i] && p[j]) {
				cout << i << " " << j << endl;
				break;
			}

    return 0;
}