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

vector < int > g[32];
int x, cc;
bool v[32];
bool b[32][32];
int a[32];

void dfs(int dep) {
	if (dep > 20) {
		if (b[a[dep-1]][a[1]]) {
			printf("%d: ", ++cc);
			for (int i = 1; i <= 20; ++ i)
				printf(" %d", a[i]);
			printf(" %d\n", a[1]);
		}
		return;
	}
	for (int i = 0; i < g[a[dep-1]].size(); ++ i) 
		if (!v[g[a[dep-1]][i]]) {
			a[dep] = g[a[dep-1]][i];
			v[a[dep]] = true;
			dfs(dep + 1);
			v[a[dep]] = false;
		}
}

int main() {

	memset(b, 0, sizeof(b));
    for (int i = 1; i <= 20; ++ i) {
    	g[i].clear();
    	for (int j = 0; j < 3; ++ j) {
    		cin >> x;
    		g[i].push_back(x);
    		b[i][x] = true;
    	}
    	sort(g[i].begin(), g[i].end());
    }

    while (cin >> x) {
    	if (x == 0) break;
    	a[1] = x, cc = 0;
    	memset(v, 0, sizeof(v));
    	v[x] = true;
    	dfs(2);
    }

    return 0;
}