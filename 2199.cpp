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
#define eps 1e-9

using namespace std;

double n;
double l, r, mid;

double f(double x) {
	return (8*x*x*x*x + 7*x*x*x + 2*x*x + 3*x + 6);
}

int main() {

	scanf("%lf", &n);
	while (scanf("%lf", &n) == 1) {
		if (n < f(-eps) || n > f(100+eps)) {
			printf("No solution!\n");
			continue;
		}
		l = 0, r = 100;
		while (r-l > eps) {
			mid = (l+r) / 2.0;
			if (f(mid) > n) r = mid-eps;
			else l = mid;
		}
		printf("%.4lf\n", l);
	}

    return 0;
}