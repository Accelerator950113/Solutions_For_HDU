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

int T, n;
char s[8192];
double x, y;
bool flag;

int main() {

	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		double tot1 = 0, tot2 = 0;
		flag = true;
		while (n --) {
			scanf("%s%lf%lf", s, &x, &y);
			if (y < 60) flag = false;
			tot1 += x;
			tot2 += (x*y);
		}
		if (flag) printf("%.2lf\n", tot2 / tot1);
		else printf("Sorry!\n");
		if (T) printf("\n");
	}

    return 0;
}
