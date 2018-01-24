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

struct node {
	int s, t;
	node() {}
	void readin() {
		scanf("%d%d",&s,&t);
		if (s > t) swap(s, t);
		s ++;
	}
	friend bool operator <(const node &a1, const node &a2) {
		return (a1.t < a2.t);
	}
};

int n;
node a[1024];

int main() {

	while (scanf("%d", &n) == 1) {
		if (n <= 0) break;
		for (int i = 0; i < n; ++ i)
			a[i].readin();
		sort(a, a + n);
		int ans = 1, tt = a[0].t;
		for (int i = 1; i < n; ++ i)
			if (a[i].s > tt) {
				tt = a[i].t;
				ans ++;
			}
		printf("%d\n", ans);
	}

    return 0;
}
