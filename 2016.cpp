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

int n, m;
int a[1024];

int main() {

	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		for (int i = 0; i < n; ++ i)
			scanf("%d", a + i);
		int id = 0;
		for (int i = 1; i < n; ++ i)
			if (a[i] < a[id]) id = i;
		swap(a[0], a[id]);
		printf("%d", a[0]);
		for (int i = 1; i < n; ++ i)
			printf(" %d", a[i]);
		printf("\n");
	}

    return 0;
}
