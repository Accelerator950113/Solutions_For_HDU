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

double x1, x2, _y1, y2;
double x3, x4, y3, y4;

double cross(double a1, double a2, double b1, double b2) {
	double c1 = max(a1, b1);
	double c2 = min(a2, b2);
	if (c1 > c2) return 0;
	return (c2 - c1);
}

int main() {

	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &_y1, &x2, &y2, &x3, &y3, &x4, &y4) != EOF)
		printf("%.2lf\n", cross(min(x1, x2), max(x1, x2), min(x3, x4), max(x3, x4)) *
						cross(min(_y1, y2), max(_y1, y2), min(y3, y4), max(y3, y4)));

    return 0;
}
