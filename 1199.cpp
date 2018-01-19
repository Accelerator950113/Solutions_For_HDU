#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct qj {
	int l,r;
	qj() {}
	void set(int _l,int _r) {
		l = _l;
		r = _r;
	}
};

map < int, int > M;
int succ[8192];
qj A[8192];
bool W[8192];
int n,m;
int Left[2048],Right[2048];
bool Color[2048]; // true : white ; false : black
char ch;
bool fst;

bool getColor() {
	ch = getchar();
	while (!isalpha(ch))
		ch = getchar();
	if (ch == 'w') return true;
	return false;
}

int nxt(int x) {
	if (succ[x] != x) succ[x] = nxt(succ[x]);
	return succ[x];
}

int main() {

	while (scanf("%d",&n) != EOF) {
		M.clear();
		for (int i = 1;i <= n;++ i) {
			scanf("%d%d",&Left[i],&Right[i]);
			if (Left[i] > Right[i]) swap(Left[i],Right[i]);
			M[Left[i]] = 1;
			M[Right[i]] = 1;
			Color[i] = getColor();
		}
		m = 0;
		for (map < int, int > :: iterator it = M.begin();it != M.end();++ it) 
			if (m == 0) {
				A[++ m].set(it -> first, it -> first);
				it -> second = m;
			}
			else {
				if ((A[m].r + 1) == it -> first) {
					A[++ m].set(it -> first, it -> first);
					it -> second = m;
				}
				else {
					++ m;
					A[m].set(A[m - 1].r + 1, it -> first - 1);
					A[++ m].set(it -> first, it -> first);
					it -> second = m;
				}
			}
		memset(W,0,sizeof(W));
		for (int i = 1;i <= (m + 1);++ i)
			succ[i] = i;
		for (int i = 1;i <= n;++ i) {
			Left[i] = M[Left[i]];
			Right[i] = M[Right[i]];
		}
		for (int i = n;i > 0;-- i) 
			for (int j = nxt(Left[i]);j <= Right[i];j = nxt(j + 1)) {
					W[j] = Color[i];
					succ[j] = nxt(Right[i] + 1);
			}
		int ans = 0, ansl = -1, ansr = -1, tou = -1;
		for (int i = 1;i <= m;++ i) {
			if (W[i]) {
				if (tou == -1) tou = A[i].l;
			}
			else {
				if (tou != -1) tou = -1;
			}
			if (tou != -1) {
				if ((A[i].r - tou + 1) > ans) {
					ans = A[i].r - tou + 1;
					ansl = tou;
					ansr = A[i].r;
				}
			}
		}
		if (ans == 0) puts("Oh, my god");
		else printf("%d %d\n",ansl,ansr);
	}
    
    return 0;
}
