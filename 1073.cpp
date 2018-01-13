#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

class buffer {
	private:
		char s[16];
		int p;
	public:
		void init() {
			p = 0;
		}
		void read() {
			p = (p + 1) & 7;
			s[p] = getchar();
		}
		bool checkBegin() {
			return ((s[(p+3)&7] == '\n') && (s[(p+4)&7] == 'S') &&
				(s[(p+5)&7] == 'T') && (s[(p+6)&7] == 'A') &&
				(s[(p+7)&7] == 'R') && (s[p] == 'T'));
		}
		bool checkEnd() {
			return ((s[(p+5)&7] == '\n') && (s[(p+6)&7] == 'E') &&
				(s[(p+7)&7] == 'N') && (s[p] == 'D'));
		}
		char getcnt() {
			return s[p];
		}
};

buffer B;
int T;
char a[131072],b[131072],c[131072],d[131072];
int la,lb,lc,ld;

int main() {

	scanf("%d",&T);
	B.init();
	while (T --) {
		while (!B.checkBegin())
			B.read();
		la = lb = 0;
		char tc;
		while (!B.checkEnd()) {
			B.read();
			tc = B.getcnt();
			if ((tc != ' ') && (tc != '\n') && (tc != '\t')) {
				a[la ++] = tc;
				b[lb ++] = tc;
			}
			else a[la ++] = tc;
		}
		a[la] = b[lb] = '\0';
		while (!B.checkBegin())
			B.read();
		lc = ld = 0;
		while (!B.checkEnd()) {
			B.read();
			tc = B.getcnt();
			if ((tc != ' ') && (tc != '\n') && (tc != '\t')) {
				c[lc ++] = tc;
				d[ld ++] = tc;
			}
			else c[lc ++] = tc;
		}
		c[lc] = d[ld] = '\0';
		if (strcmp(a,c) == 0) puts("Accepted");
		else {
			if (strcmp(b,d) == 0) puts("Presentation Error");
			else puts("Wrong Answer");
		}
	}

    return 0;
}