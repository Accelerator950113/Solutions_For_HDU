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

int t,n;
double x,y;

int main() {

	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		scanf("%lf",&x);
		for (int i = 1;i < n;++ i) {
			scanf("%lf",&y);
			if (y > x) x = y;
		}
		printf("%.2lf\n",x);
	}

    return 0;
}
