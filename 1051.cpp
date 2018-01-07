#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

struct node {
	int x,y;
	node () {}
	void readin() {
		scanf("%d%d",&x,&y);
	}
	friend bool operator <(const node &a1,const node &a2) {
		if (a1.x == a2.x) return (a1.y < a2.y);
		return (a1.x < a2.x);
	}
} A[8192];

int p[8192],l;
int n;
int tmax,tid;

int main() {

	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i = 1;i <= n;++ i)
			A[i].readin();
		sort(A + 1,A + n + 1);
		l = 0;
		for (int i = 1;i <= n;++ i) {
			tmax = -INF;
			for (int j = 1;j <= l;++ j)
				if ((p[j] <= A[i].y) && (p[j] > tmax)) {
					tmax = p[j];
					tid = j;
				}
			if (tmax == -INF) p[++ l] = A[i].y;
			else p[tid] = A[i].y;
		}
		printf("%d\n",l);
	}

    return 0;
}
