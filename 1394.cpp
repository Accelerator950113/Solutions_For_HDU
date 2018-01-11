#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#define Lowbit(x) ((x) & (-x))

using namespace std;

int n,ans,minans;
int s[8192];
int x[8192];

void add(int x,int inc) {
	while (x <= n) {
		s[x] += inc;
		x += Lowbit(x);
	}
}

int getsum(int x) {
	int ts = 0;
	while (x > 0) {
		ts += s[x];
		x -= Lowbit(x);
	}
	return ts;
}

int main() {

	while (scanf("%d",&n) == 1) {
		for (int i = 0;i < n;++ i) {
			scanf("%d",&x[i]);
			x[i] ++;
		}
		ans = 0;
		memset(s,0,sizeof(s));
		for (int i = 0;i < n;++ i) {
			ans += (getsum(n) - getsum(x[i]));
			add(x[i],1);
		}
		minans = ans;
		for (int i = 0;i < n;++ i) {
			ans -= (x[i] - 1);
			ans += (n - x[i]);
			if (ans < minans) minans = ans;
		}
		cout << minans << endl;
	}

    return 0;
}
