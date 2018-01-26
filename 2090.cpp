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

string s;
double sum, x, y;

int main() {

	sum = 0;
	while (cin >> s >> x >> y)
		sum += (x*y);
	printf("%.1lf\n", sum);

    return 0;
}
