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

int T;
int n;
double x[1048576], y[1048576];
double tp;
double area;
double totx, toty;

int main() {

	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) 
			scanf("%lf%lf", &x[i], &y[i]);
		x[n] = x[0], y[n] = y[0];
		area = totx = toty = 0;
		for (int i = 0; i < n; ++ i) {
			tp = (x[i]*y[i+1] - x[i+1]*y[i]);
			area += tp/2;
			totx += (x[i] + x[i+1]) * tp;
			toty += (y[i] + y[i+1]) * tp;
		}

		printf("%.2lf %.2lf\n", totx/(6*area), toty/(6*area));
	}

    return 0;
}