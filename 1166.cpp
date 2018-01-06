#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define Lowbit(x) ((x) & (-x))

using namespace std;

long long s[131072];
int n,x;
char sh[15];

void add(int pos,long long x) {
	int t = pos;
	while (t <= n) {
		s[t] += x;
		t = t + Lowbit(t);
	}
}

long long sum(int pos) {
	int t = pos;
	long long ts = 0;
	while (t > 0) {
		ts += s[t];
		t -= Lowbit(t);
	}
	return ts;
}

int main() {

	int T,ins,cst = 0,x,y;
	scanf("%d",&T);
	while (T --) {
		printf("Case %d:\n",++ cst);
		scanf("%d",&n);
		memset(s,0,sizeof(s));
		for (int i = 1;i <= n;++ i) { 
			scanf("%d",&x);
			add(i,(long long)x);
		}
		while (scanf("%s",sh)) {
			if (sh[0] == 'E') break;
			scanf("%d%d",&x,&y);
			if (sh[0] == 'A') add(x,(long long)y);
			else if (sh[0] == 'S') add(x,(long long)(-y));
			else if (sh[0] == 'Q') printf("%d\n",(int)(sum(y) - sum(x - 1)));
		}
	}
    
    return 0;
}
