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

using namespace std;

int n;
int a[1024];
double tot;

int main() {

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; ++ i)
			scanf("%d", a + i);
		sort(a, a + n);
		tot = 0;
		for (int i = 1; i < n-1; ++ i)
			tot += a[i];
		printf("%.2lf\n", tot / (n-2));
	}

    return 0;
}
