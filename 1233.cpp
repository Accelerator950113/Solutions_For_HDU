#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct edge	{
	int x,y,d;
	edge () {}
	void readin() {
		scanf("%d%d%d",&x,&y,&d);
	}
	friend bool operator <(const edge &a1,const edge &a2) {
		return (a1.d < a2.d);
	}
};

edge E[16384];
int n,m;
int f[512];
int ans;

int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

int main() {

	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		m = n * (n - 1);
		m /= 2;
		for (int i = 1;i <= n;++ i)
			f[i] = i;
		for (int i = 0;i < m;++ i)
			E[i].readin();
		sort(E,E + m);
		ans = 0;
		for (int i = 0;i < m;++ i) 
			if (find(E[i].x) != find(E[i].y)) {
				f[find(E[i].x)] = find(E[i].y);
				ans += E[i].d;
			}
		cout << ans << endl;
	}

    return 0;
}
