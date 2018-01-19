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

class reader {
	private:
		int x;
		char ch;
	public:
		reader() {}
		int readint() {
			scanf("%d",&x);
			return x;
		}
		int readunit() {
			ch = getchar();
			while ((!isalpha(ch)) && (ch != '*') && (ch != '@') && (ch != '<') && (ch != '.'))
				ch = getchar();
			if (isalpha(ch)) return (ch - 'A' + 4);
			if (ch == '*') return 0;
			if (ch == '@') return 2;
			if (ch == '<') return 3;
			return 1;
		}
};

class constant {
	private:
		int dx[4],dy[4];
	public:
		constant() {
			memset(dx,0,sizeof(dx));
			memset(dy,0,sizeof(dy));
			dx[0] = 1, dx[1] = -1;
			dy[2] = 1, dy[3] = -1;
		}
		int getdx(int x) {
			return dx[x];
		}
		int getdy(int y) {
			return dy[y];
		}
};

class position {
	private:
		int x,y;
	public:
		position() {}
		position(int _x,int _y) {
			x = _x, y = _y;
		}
		void trans(constant* t, int i) {
			x += (*t).getdx(i);
			y += (*t).getdy(i);
		}
		int getx() {
			return x;
		}
		int gety() {
			return y;
		}
};

class Information {
	private:
		int n,m;
		int a[64][64];
		int Num,Limit;
		position b[16];
		int v[16];
	public:
		Information() {}
		void readin(reader* r) {
			memset(a,0,sizeof(a));
			m = (*r).readint();
			n = (*r).readint();
			Limit = (*r).readint();
			Num = (*r).readint();
			for (int i = 1;i <= Num;++ i)
				v[i] = (*r).readint();
			for (int i = 1;i <= n;++ i)
				for (int j = 1;j <= m;++ j) {
					a[i][j] = (*r).readunit();
					if (a[i][j] == 2) b[Num + 1] = position(i,j);
					if (a[i][j] == 3) b[Num + 2] = position(i,j);
					if (a[i][j] > 3) b[a[i][j] - 3] = position(i,j);
				}
		}
		int getMap(position a1) {
			return a[a1.getx()][a1.gety()];
		}
		position getStart() {
			return b[Num + 1];
		}
		position getEnd() {
			return b[Num + 2];
		}
		position getGemPos(int x) {
			return b[x];
		}
		int getGemValue(int x) {
			return v[x];
		}
		int getNum() {
			return Num;
		}
		int getLimit() {
			return Limit;
		}
};

class Distance {
	private:
		int d[64][64];
	public:
		Distance() {}
		void init() {
			memset(d,0x3f,sizeof(d));
		}
		void update(position a1, int x) {
			d[a1.getx()][a1.gety()] = x;
		}
		int getdis(position a1) {
			return d[a1.getx()][a1.gety()];
		}
};

class Graph {
	private:
		int A[16][16];
		int N, Limit;
		int Value[16];
		Information Info;
		Distance Dis;
		queue < position > Q;
		reader R;
		constant C;
		int ans,now;
		int lst[16],l;
		bool visit[16];
	public:
		Graph() {}
		void Prepare() {
			Info.readin(&R);
			N = Info.getNum() + 2;
			for (int i = 1;i <= (N - 2);++ i)
				Value[i] = Info.getGemValue(i);
			Limit = Info.getLimit();
		}
		void getGraph() {
			position cnt,nxt;
			for (int i = 1;i < N;++ i) {
				Dis.init();
				while (!Q.empty())
					Q.pop();
				Dis.update(Info.getGemPos(i), 0);
				Q.push(Info.getGemPos(i));
				while (!Q.empty()) {
					cnt = Q.front();
					Q.pop();
					for (int dir = 0;dir < 4;++ dir) {
						nxt = cnt;
						nxt.trans(&C, dir);
						if (Info.getMap(nxt) == 0) continue;
						if ((Dis.getdis(cnt) + 1) < Dis.getdis(nxt)) {
							Dis.update(nxt, Dis.getdis(cnt) + 1);
							Q.push(nxt);
						}
					}
				}
				for (int j = 1;j <= N;++ j)
					A[i][j] = A[j][i] = Dis.getdis(Info.getGemPos(j));
			}
		}
		void show() {
			for (int i = 1;i <= N;++ i) {
				for (int j = 1;j <= N;++ j)
					printf("%8d",A[i][j]);
				printf("\n");
			}
		}
		void dfs(int dep, int res) {
			if (A[lst[l]][N] > res) return;
			ans = max(ans, now);
			if (dep > N) return;
			for (int i = 1;i <= (N - 2);++ i)
				if (!visit[i]) {
					visit[i] = true;
					lst[++ l] = i;
					now += Value[i];
					dfs(dep + 1, res - A[lst[l]][lst[l - 1]]);
					now -= Value[i];
					l --;
					visit[i] = false;
				}
		}
		int calc() {
			memset(visit,0,sizeof(visit));
			now = 0;
			l = 0;
			lst[0] = N - 1;
			ans = -1;
			dfs(1, Limit);
			return ans;
		}

};

class Solver {
	private:
		Graph G;
		int result;
	public:
		Solver() {}
		void print(int cst, int x) {
			if (cst != 1) putchar('\n');
			printf("Case %d:\n",cst);
			if (x == -1) puts("Impossible");
			else printf("The best score is %d.\n",x);
		}
		void work(int cst) {
			G.Prepare();
			G.getGraph();
			//G.show();
			print(cst, G.calc());
		}
};

Solver S;

int main() {

	int T;
	scanf("%d",&T);
	for (int i = 1;i <= T;++ i)
		S.work(i);

    return 0;
}
