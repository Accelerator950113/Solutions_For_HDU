#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct node {
	int id,w,s;
	node () {}
	friend bool operator <(const node &a1,const node &a2) {
		return (a1.w < a2.w);
	}
};

node A[1024];
int f[1024];
int pre[1024];

void print(int x) {
	if (x == -1) return;
	print(pre[x]);
	printf("%d\n",A[x].id);
}

int main() {

	int n = 0;
	int xx,yy;
    while (scanf("%d%d",&xx,&yy) == 2) {
    	n ++;
    	A[n].id = n;
    	A[n].w = xx;
    	A[n].s = yy;
    }
    sort(A + 1,A + n + 1);
    memset(pre,0xff,sizeof(pre));
    for (int i = 1;i <= n;++ i) {
    	f[i] = 1;
    	for (int j = 1;j < i;++ j)
    		if (((A[j].w < A[i].w) && (A[j].s > A[i].s)) && ((f[j] + 1) > f[i])) {
    			pre[i] = j;
    			f[i] = f[j] + 1;
    		}
    }
    int maxn = 1;
    for (int i = 2;i <= n;++ i)
    	if (f[i] > f[maxn]) maxn = i;
	printf("%d\n",f[maxn]);
	print(maxn);    
    return 0;
}
