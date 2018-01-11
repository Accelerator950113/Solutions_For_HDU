#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct node	{
	int x,y,z;
	node () {}
	node (int _x,int _y,int _z) {
		if (_x > _y) {
			x = _y;
			y = _x;
		}
		else {
			x = _x;
			y = _y;
		}
		z = _z;
	}
	friend bool operator <(const node &a1,const node &a2) {
		if (a1.x == a2.x) return (a1.y < a2.y);
		return (a1.x < a2.x);
	}
};

node A[512];
int f[512];
int n,l,cst = 0;
int tx,ty,tz;

int main() {

	while (cin >> n) {
		if (n == 0) break;
		l = 0;
		for (int i = 1;i <= n;++ i) {
			cin >> tx >> ty >> tz;
			A[++ l] = node(tx,ty,tz);
			A[++ l] = node(tz,ty,tx);
			A[++ l] = node(tx,tz,ty);
		}
		sort(A + 1,A + l + 1);
		memset(f,0,sizeof(f));
		int ans = 0;
		for (int i = 1;i <= l;++ i) {
			f[i] = A[i].z;
			for (int j = 1;j < i;++ j)
				if ((A[j].x < A[i].x) && (A[j].y < A[i].y) && (f[j] + A[i].z > f[i])) f[i] = f[j] + A[i].z;
			if (f[i] > ans) ans = f[i];
		}
		cout << "Case " << ++ cst;
		cout << ": maximum height = ";
		cout << ans << endl;
	}

    return 0;
}
