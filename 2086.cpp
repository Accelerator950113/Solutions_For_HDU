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

int n;
double zuo[4096], zhu[4096], you[4096], Y[4096];
double C[4096];
double xs;

int main() {

	while (scanf("%d", &n) != EOF) {
		scanf("%lf%lf", &C[0], &C[n+1]);
		for (int i = 1; i <= n; ++ i)
			scanf("%lf", &C[i]);
		if (n == 1) {
			printf("%.2lf\n", (C[0]+C[n+1])/2.0-C[1]);
			continue;
		}
		for (int i = 1;i <= n; ++ i)
			zuo[i] = -0.5, zhu[i] = 1.0, you[i] = -0.5, Y[i] = -C[i];
		zuo[1] = 0, you[n] = 0;
		Y[1] += 0.5*C[0], Y[n] += 0.5*C[n+1];
		for (int i = 2; i <= n; ++ i) {
			xs = -(zuo[i] / zhu[i-1]);
			zuo[i] = 0;
			zhu[i] += xs*you[i-1];
			Y[i] += xs*Y[i-1];
		}
		for (int i = n-1; i > 0; -- i) {
			xs = -(you[i] / zhu[i+1]);
			you[i] = 0;
			Y[i] += xs*Y[i+1];
		}
		printf("%.2lf\n", Y[1]/zhu[1]);
	}

    return 0;
}
