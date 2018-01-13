#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct node {
	char Name[256];
	int deadLine,cost;
	node () {}
	void readin() {
		scanf("%s%d%d",Name,&deadLine,&cost);
	}
	friend bool operator <(const node &a1,const node &a2) {
		return (strcmp(a1.Name,a2.Name) > 0);
	}
};

node A[32];
int T,n;
int f[65536];
int sum[65536];
int pre[65536];

void output(int x) {
	if (x == 0) return;
	output(x - (1 << pre[x]));
	puts(A[pre[x]].Name);
}

int main() {

	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i = 0;i < n;++ i)
			A[i].readin();
		sort(A, A + n);
		memset(f, 0x3f, sizeof(f));
		memset(pre, 0xff, sizeof(pre));
		memset(sum, 0, sizeof(sum));
		f[0] = 0;
		for (int i = 1; i < (1 << n); ++ i) 
			for (int j = 0; j < n; ++ j)
				if (i & (1 << j)) {
					sum[i] = sum[i - (1 << j)] + A[j].cost;
					if (sum[i] <= A[j].deadLine) {
						if (f[i - (1 << j)] < f[i]) { 
							f[i] = f[i - (1 << j)];
							pre[i] = j;
						}
					}
					else {
						if (f[i - (1 << j)] + sum[i] - A[j].deadLine < f[i]) {
							f[i] = f[i - (1 << j)] + sum[i] - A[j].deadLine;
							pre[i] = j;
						}
					}
				}
		printf("%d\n",f[(1 << n) - 1]);
		output((1 << n) - 1);
	}

    return 0;
}