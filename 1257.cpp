#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int a[16384];
int b[16384];
int l,n;
bool ok;
int oid;

int main() {

	while (scanf("%d",&n) == 1) {
		for (int i = 1;i <= n;++ i)
			scanf("%d",&a[i]);
		l = 1;
		b[1] = a[1];
		for (int i = 2;i <= n;++ i) {
			ok = false;
			oid = -1;
			for (int j = 1;j <= l;++ j)
				if (b[j] >= a[i]) {
					ok = true;
					if (oid == -1) oid = j;
					if (b[j] < b[oid]) oid = j;
				}
			if (ok) b[oid] = a[i];
			else b[++ l] = a[i];
		}
		printf("%d\n",l);
	}

    return 0;
}
