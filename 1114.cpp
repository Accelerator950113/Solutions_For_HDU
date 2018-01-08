#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T;
int W1,W2,W;
int n;
int f[16384];
int w[512],p[512];

int main() {

	scanf("%d",&T);
	while (T --) {
		memset(f,0x3f,sizeof(f));
		f[0] = 0;
		scanf("%d%d",&W1,&W2);
		W = W2 - W1;
		scanf("%d",&n);
		for (int i = 1;i <= n;++ i) 
			scanf("%d%d",&p[i],&w[i]);
		for (int i = 1;i <= n;++ i)
			for (int j = w[i];j <= W;++ j)
				if ((f[j - w[i]] + p[i]) < f[j]) f[j] = f[j - w[i]] + p[i];
		if (f[W] == f[W + 1]) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",f[W]);
	}

    return 0;
}
