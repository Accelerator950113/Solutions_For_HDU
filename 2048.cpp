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

using namespace std;

long long d[32], p[32];
double ans[32];

int main() {

	d[1] = 0, d[2] = 1;
	for (int i = 3; i <= 20; ++ i)
		d[i] = (i-1) * (d[i-1] + d[i-2]);
	p[1] = 1;
	for (int i = 2; i <= 20; ++ i)
		p[i] = i * p[i - 1];
	for (int i = 1; i <= 20; ++ i)
		ans[i] = (double)d[i] / p[i];

	int n;
	scanf("%d", &n);
	while (scanf("%d", &n) != EOF) 
		printf("%.2lf%%\n", ans[n] * 100.0); 


    return 0;
}
