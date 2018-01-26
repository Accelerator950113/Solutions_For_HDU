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

string a, b;
int x, y;
int d[2048];
bool f[2048];
vector < int > g[2048];
map < string , int > M;
int n, m;
bool flag;

void dfs(int x) {
	if (f[x]) return;
	f[x] = true;
	for (int i = 0; i < g[x].size(); ++ i)
		if (!f[g[x][i]]) dfs(g[x][i]);
}

int main() {

	while (cin >> m) {
		if (m == 0) break;
		for (int i = 1; i <= 2000; ++ i)
			g[i].clear();
		M.clear();
		memset(d, 0, sizeof(d));
		flag = true;
		n = 0;
		while (m --) {
			cin >> a >> b;
			if (!M.count(a)) M[a] = ++n;
			if (!M.count(b)) M[b] = ++n;
			x = M[a];
			y = M[b];
			g[x].push_back(y); 
			d[y] ++;
		}
		int cc = 0, cid;
		for (int i = 1; i <= n; ++ i)
			if (d[i] == 0) cc ++, cid = i;
		if (cc != 1) flag = false;
		if (flag) {
			memset(f, 0, sizeof(f));
			dfs(cid);
			for (int i = 1; i <= n; ++ i)
				if (!f[i]) flag = false;
		}
		cout << ((flag) ? ("Yes") : ("No")) << endl;
	}

    return 0;
}
