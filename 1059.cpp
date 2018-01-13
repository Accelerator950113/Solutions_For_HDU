#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

bool f[131072];
int v[1024];
int a[8];
int n;
int cst = 0;

int main() {

	while (true) {
		int sum = 0;
		for (int i = 1;i <= 6;++ i) {
			cin >> a[i];
			sum += (a[i]*i);
		}
		if (sum == 0) break;
		printf("Collection #%d:\n", ++ cst);
		if (sum & 1) {
			printf("Can't be divided.\n\n");
			continue;
		}
		n = 0;
		for (int i = 1;i <= 6;++ i)
			if (a[i] > 0) {
				for (int j = 1;j < a[i];j *= 2) {
					a[i] -= j;
					v[++ n] = j*i;
				}
				if (a[i]) v[++ n] = a[i]*i;
			}
		memset(f,0,sizeof(f));
		f[0] = true;
		for (int i = 1;i <= n;++ i)
			for (int j = sum;j >= v[i];-- j)
				f[j] |= f[j - v[i]];
		if (f[sum / 2]) printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}

    return 0;
}