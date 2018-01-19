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

struct node {
	int id, sum, ans, num;
	node() {}
	void set(int _id, int x) {
		id = _id;
		sum = ans = x;
		num = 1;
	}
	friend bool operator <(const node &a1, const node &a2) {
		return ((a1.sum * a2.num) < (a2.sum * a1.num));
	}
	void merge(const node &a2) {
		ans = ans + a2.ans + a2.sum * num;
		sum += a2.sum;
		num += a2.num;
	}
};

vector < int > G[1024];
int fa[1024];
int n,root,x,y;
int f[1024];
node A[1024];
priority_queue < node > Q;

void dfs(int x) {
	for (int i = 0;i < G[x].size();++ i)
		if (fa[G[x][i]] == -1) {
			fa[G[x][i]] = x;
			dfs(G[x][i]);
		}
}

int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

int main() {

	while (scanf("%d%d", &n, &root) != EOF) {
		if (n < 1) break;
		while (!Q.empty()) 
			Q.pop();
		for (int i = 1; i <= n; ++ i) {
			G[i].clear();
			scanf("%d", &x);
			A[i].set(i, x);
			Q.push(A[i]);
		}
		for (int i = 1; i < n; ++ i) {
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		memset(fa, 0xff, sizeof(fa));
		fa[root] = 0;
		dfs(root);
		for (int i = 1; i <= n; ++ i)
			f[i] = i;
		node cnt;
		int tf;
		for (int i = 1; i < n; ++ i) {
			while ((Q.top().id == root) || (Q.top().num != A[Q.top().id].num))
				Q.pop();
			cnt = Q.top();
			Q.pop();
			tf = find(fa[cnt.id]);
			A[tf].merge(cnt);
			f[cnt.id] = tf;
			Q.push(A[tf]);
		} 
		printf("%d\n",A[root].ans);
	}

    return 0;
}
