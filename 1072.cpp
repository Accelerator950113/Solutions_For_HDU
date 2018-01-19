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
	public:
		reader() {}
		int readint() {
			scanf("%d",&x);
			return x;
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

class Map {
	private:
		int n,m;
		int a[16][16];
		position st,ed;
	public:
		Map() {}
		void readin(reader* r) {
			memset(a,0,sizeof(a));
			n = (*r).readint();
			m = (*r).readint();
			for (int i = 1;i <= n;++ i)
				for (int j = 1;j <= m;++ j) {
					a[i][j] = (*r).readint();
					if (a[i][j] == 2) st = position(i,j);
					if (a[i][j] == 3) ed = position(i,j);
				}
		}
		int getMap(position a1) {
			return a[a1.getx()][a1.gety()];
		}
		position getStart() {
			return st;
		}
		position getEnd() {
			return ed;
		}
};

class Distance {
	private:
		int dis[16][16][8];
	public:	
		Distance() {}
		void init() {
			memset(dis,0x3f,sizeof(dis));
		}
		void update(position a1, int t, int x) {
			dis[a1.getx()][a1.gety()][t] = x;
		}
		int getdis(position a1, int t) {
			return dis[a1.getx()][a1.gety()][t];
		}
};

class Solver {
	private:
		Map M;
		constant C;
		reader R;
		queue < position > Q;
		queue < int > Q2;
		Distance D;
	public:
		Solver() {}
		void Init() {
			M.readin(&R);
			D.init();
			while (!Q.empty())
				Q.pop();
			while (!Q2.empty()) 
				Q2.pop();
		}
		void solve() {
			Q.push(M.getStart());
			Q2.push(6);
			D.update(M.getStart(), 6, 0);
			position cnt, nxt;
			int cnt2, nxt2;
			while (!Q.empty()) {
				cnt = Q.front();
				Q.pop();
				cnt2 = Q2.front();
				Q2.pop();
				if (cnt2 == 1) continue;
				for (int i = 0;i < 4;++ i) {
					nxt = cnt, nxt2 = cnt2 - 1;
					nxt.trans(&C, i);
					if (M.getMap(nxt) == 0) continue;
					if (M.getMap(nxt) == 4) nxt2 = 6;
					if ((D.getdis(cnt, cnt2) + 1) < D.getdis(nxt, nxt2)) {
						D.update(nxt, nxt2, D.getdis(cnt, cnt2) + 1);
						Q.push(nxt);
						Q2.push(nxt2);
					}
				}
			}
			int ans = D.getdis(position(0, 0), 0);
			for (int i = 1;i <= 6;++ i)
				ans = min(ans, D.getdis(M.getEnd(), i));
			if (ans == D.getdis(position(0, 0), 0)) puts("-1");
			else printf("%d\n",ans);
		}
};

Solver S;

int main() {

	int T;
	scanf("%d",&T);
	while (T --) {
		S.Init();
		S.solve();
	}

    return 0;
}
