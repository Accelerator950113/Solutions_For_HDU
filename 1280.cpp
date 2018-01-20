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

int n,m;
int a[4096];
priority_queue < int > Q;

int main() {

	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 1;i <= n;++ i)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		while (!Q.empty())
			Q.pop();
		for (int i = 1;(i*(i-1) / 2) < m;++ i)
			for (int j = i+1;j <= n;++ j)
				Q.push(a[i]+a[j]);
		printf("%d", Q.top());
		Q.pop();
		for (int i = 1;i < m;++ i) {
			printf(" %d", Q.top());
			Q.pop();
		}
		printf("\n");
	}

    return 0;
}
