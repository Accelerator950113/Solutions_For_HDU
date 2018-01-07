#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-6

using namespace std;

double f[16384];
double x;
int l,r,mid;

int main() {

	f[0] = 0;
	for (int i = 1;i <= 10000;++ i)
		f[i] = f[i - 1] + (1.0 / (double)(i + 1));

	while (scanf("%lf",&x) == 1) {
		if (x < eps) break;
		l = 1, r = 10000;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[mid] < x) l = mid + 1;
			else r = mid - 1;
		}
		printf("%d card(s)\n",l);
	}

    return 0;
}
