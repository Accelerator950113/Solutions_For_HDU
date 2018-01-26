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

using namespace std;

long long c[32][32];
long long p[32];
long long t[32];
int n;
long long m;
int L[32];
vector < int > ans;

void del(int x) {
	int tp = 0;
	while (L[tp] != x) 
		tp = L[tp];
	L[tp] = L[x];
}

int main() {

	c[0][0] = 1;
	for (int i = 1; i <= 20; ++ i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++ j)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	p[0] = 1;
	for (int i = 1; i <= 20; ++ i)
		p[i] = p[i-1]*i;
	for (int i = 1; i <= 20; ++ i) {
		t[i] = 0;
		for (int j = 1; j <= i; ++ j)
			t[i] += (c[i][j]*p[j]);
	}

	while (cin >> n >> m) {
		for (int i = 0; i <= n; ++ i)
			L[i] = i+1;
		L[n+1] = n+1;
		ans.clear();
		int fst = 1;
		while (m > t[n-1]+1)
			fst ++, m -= (t[n-1]+1);
		ans.push_back(fst);
		del(fst);
		for (int i = n-1; i > 0; -- i) {
			if (m == 1) break;
			m --;
			fst = L[0];
			while (m > t[i-1]+1)
				fst = L[fst], m -= (t[i-1]+1);
			ans.push_back(fst);
			del(fst);
		}
		cout << ans[0];
		for (int i = 1; i < ans.size(); ++ i)
			cout << " " << ans[i];
		cout << endl;
	}

    return 0;
}
