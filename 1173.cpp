#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-6

using namespace std;

double x[1048576],y[1048576];
int n;

int main() {

	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		for (int i = 0;i < n;++ i)
			scanf("%lf%lf",&x[i],&y[i]);
		sort(x, x + n);
		sort(y, y + n);
		printf("%.2lf %.2lf\n", x[n / 2], y[n / 2]);
	}

    return 0;
}
