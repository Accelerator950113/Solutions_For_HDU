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
#define PI 3.14159265

using namespace std;

int n, m;
int c;

int main() {

	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		c = 0;
		n *= 100;
		for (int i = 0; i < 100; ++ i)
			if ((n + i) % m == 0) {
				if (c++ > 0) putchar(' ');
				printf("%02d", i);
			}
		putchar('\n');
	}

    return 0;
}
