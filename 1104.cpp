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

int N, M, K, km;
queue < int > Q;
int dis[1048576];
int pre[1048576];
int Cnt[1048576];

int f(int x) {
	return (x % km + km) % km;
}

void update(int x, int y, int c) {
	if ((dis[x] + 1) < dis[y]) {
		Q.push(y);
		dis[y] = dis[x] + 1;
		pre[y] = x;
		Cnt[y] = c;
	}
}

void dy(int x) {
	if (x == 1) putchar('+');
	if (x == 2) putchar('-');
	if (x == 3) putchar('*');
	if (x == 4) putchar('%');
}

void output(int x, int bs) {
	if (bs == 0) return;
	output(pre[x], bs - 1);
	dy(Cnt[x]);
}

int main() {

	while (scanf("%d%d%d",&N,&K,&M) == 3) {
		if (N == 0 && M == 0 && K == 0) break;
		km = K * M;
		memset(dis, 0x7f, sizeof(dis));
		int s = f(N);
		dis[s] = 0;
		pre[s] = -1;
		bool flag = false;
		while (!Q.empty())
			Q.pop();
		Q.push(s);
		int cnt, nxt;
		while (!Q.empty()) {
			cnt = Q.front();
			Q.pop();
			if (cnt % K == (((N + 1) % K + K) % K)) {
				printf("%d\n",dis[cnt]);
				output(cnt, dis[cnt]);
				putchar('\n');
				flag = true;
				break;
			}
			nxt = (cnt + M) % km;
			update(f(cnt), f(nxt), 1);
			nxt = ((cnt - M) % km + km) % km;
			update(f(cnt), f(nxt), 2);
			nxt = (cnt * M) % km;
			update(f(cnt), f(nxt), 3);
			nxt = (cnt % M) % km;
			update(f(cnt), f(nxt), 4);
		}
		if (!flag) puts("0");
	}

    return 0;
}
