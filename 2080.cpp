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

double x[2], y[2];
double ac, jd;

double mo(double xx, double yy) {
	return sqrt(xx*xx + yy*yy);
}

int main() {

	cin >> x[0];
	while (cin >> x[0] >> y[0] >> x[1] >> y[1]) {
		ac = (x[0] * x[1] + y[0] * y[1]) / (mo(x[0], y[0]) * mo(x[1], y[1]));
		jd = acos(ac) * 180.0 / PI;
		printf("%.2lf\n", jd);
	}

    return 0;
}
