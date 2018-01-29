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
#include <set>
#include <bitset>
#include <sstream>
#define Left(i) ((i) << 1)
#define Right(i) (((i) << 1) | 1)

using namespace std;

map < double , int > M;

struct rect {
	double x[2], y[2];
	void readin() {
		scanf("%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1]);
		if (x[0] > x[1]) 
			swap(x[0], x[1]);
		if (y[0] > y[1]) 
			swap(y[0], y[1]);
	}
};

struct Line {
	double y;
	int l, r, v;
	void set(double _y, int _l, int _r, int _v) {
		y = _y, l = _l, r = _r, v = _v;
	}
	friend bool operator <(const Line &a1, const Line &a2) {
		return (a1.y < a2.y);
	}
};

struct node {
	int l, r, cnt;
	double s, ss;
	int mid() {
		return ((l+r) >> 1);
	}
};

int n, m;
rect R[2048];
Line L[4096];
node t[8192];
double ls[4096];

void build(int l, int r, int id) {
	t[id].l = l, t[id].r = r;
	t[id].cnt = 0;
	t[id].s = t[id].ss = 0;
	if (l == r) return;
	build(l, t[id].mid(), Left(id));
	build(t[id].mid()+1, r, Right(id));
}

void calc(int id) {
	if (t[id].cnt)
		t[id].s = ls[t[id].r+1] - ls[t[id].l];
	else if (t[id].l == t[id].r)
		t[id].s = 0;
	else 
		t[id].s = t[Left(id)].s + t[Right(id)].s;

	if (t[id].cnt > 1)
		t[id].ss = ls[t[id].r+1] - ls[t[id].l];
	else if (t[id].l == t[id].r)
		t[id].ss = 0;
	else if (t[id].cnt == 1)
		t[id].ss = t[Left(id)].s + t[Right(id)].s;
	else 
		t[id].ss = t[Left(id)].ss + t[Right(id)].ss;
}

void updata(int l, int r, int v, int id) {
	if (t[id].r < l || r < t[id].l)
		return;
	if (l <= t[id].l && t[id].r <= r) {
		t[id].cnt += v;
		calc(id);
		return;
	}
	updata(l, r, v, Left(id));
	updata(l, r, v, Right(id));
	calc(id);
}

int main() {

	int T;
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		M.clear();
		for (int i = 0; i < n; ++ i) {
			R[i].readin();
			M[R[i].x[0]] = 1;
			M[R[i].x[1]] = 1;
		}
		int bh = 0;
		for (map < double , int > :: iterator it = M.begin(); it != M.end(); ++ it) {
			it -> second = bh;
			ls[bh ++] = it -> first;
		}
		m = 0;
		int tl, tr;
		for (int i = 0; i < n; ++ i) {
			tl = M[R[i].x[0]], tr = M[R[i].x[1]]-1;
			L[m ++].set(R[i].y[0], tl, tr, 1);
			L[m ++].set(R[i].y[1], tl, tr, -1);
		}
		sort(L, L+m);
		build(0, bh, 1);
		double ans = 0;
		for (int i = 0;i < m-1; ++ i) {
			updata(L[i].l, L[i].r, L[i].v, 1);
			ans += t[1].ss*(L[i+1].y - L[i].y);
		}
		printf("%.2lf\n", ans+1e-6);
	}

    return 0;
}