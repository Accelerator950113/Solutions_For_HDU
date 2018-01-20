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

struct point {
	int x, y;
	point() {}
	point(int _x, int _y) {
		x = _x, y = _y;
	}
	void set(int _x, int _y) {
		x = _x, y = _y;
	}
	friend bool operator ==(const point &a1, const point &a2) {
		return ((a1.x == a2.x) && (a1.y == a2.y));
	}
};

point Right[128], Now[128], Space[8];
int m[8][16];
int xx;
int tot, ans, cou;

struct state {
	long long a[4];
	state() {}
	friend bool operator <(const state &a1, const state &a2) {
		for (int i = 0;i < 4;++ i)
			if (a1.a[i] != a2.a[i]) return (a1.a[i] < a2.a[i]);
		return false;
	}
	void get() {
		for (int i = 0;i < 4;++ i) {
			a[i] = 0;
			for (int j = 1;j <= 8;++ j)
				a[i] = (a[i]*100) + (long long)m[i+1][j];
		}
	}
} Tmp;

map < state, int > M;

void showMap() {
	for (int i = 1; i <= 4; ++ i) {
		for (int j = 1; j <= 8; ++ j)
			printf("%3d", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void setMap(point xx, int yy) {
	m[xx.x][xx.y] = yy;
}

void dfs(int dep) {
	Tmp.get();
	if (M.count(Tmp)) {
		if (M[Tmp] <= dep) return;
	}
	M[Tmp] = dep;
	//cou ++;
	if (tot == 28) {
		ans = min(ans, dep);
		return;
	}
	int tmp;
	for (int i = 1; i <= 4; ++ i) {
		tmp = m[Space[i].x][Space[i].y - 1];
		if ((tmp != 0) && (tmp % 10 != 7)) {
			tmp ++;
			if (Right[tmp] == Now[tmp]) tot --;
			else if (Right[tmp] == Space[i]) tot ++;
			setMap(Space[i], tmp);
			setMap(Now[tmp], 0);
			swap(Space[i], Now[tmp]);
			dfs(dep + 1);
			swap(Space[i], Now[tmp]);
			setMap(Now[tmp], tmp);
			setMap(Space[i], 0);
			if (Right[tmp] == Now[tmp]) tot ++;
			else if (Right[tmp] == Space[i]) tot --;
		}
	}
}

int main() {

	for (int i = 1; i <= 4; ++ i)
		for (int j = 1; j <= 7; ++ j) 
			Right[i*10 + j].set(i, j);

	int t;
	scanf("%d", &t);
	while (t --) {
		M.clear();
		memset(m, 0, sizeof(m));
		for (int i = 0; i < 28; ++ i) {
			scanf("%d", &xx);
			m[1 + (i / 7)][2 + (i % 7)] = xx;
			Now[xx].set(1 + (i / 7), 2 + (i % 7));
		}
		for (int i = 1; i < 5; ++ i) {
			Space[i] = Now[i*10 + 1];
			setMap(Now[i*10 + 1], 0);
			m[i][1] = i*10 + 1;
			Now[i*10 + 1].set(i, 1);
		}
		//showMap();
		tot = 0;
		for (int i = 1; i <= 4; ++ i)
			for (int j = 1; j <= 7; ++ j) 
				if (Right[i*10 + j] == Now[i*10 + j]) tot ++;
		ans = 10000000;
		//cou = 0;
		dfs(0);
		//printf("%d\n",cou);
		if (ans == 10000000) printf("-1\n");
		else printf("%d\n",ans);
	}

    return 0;
}
