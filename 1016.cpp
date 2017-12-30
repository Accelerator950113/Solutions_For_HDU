#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int cn = 0;
bool prime[128];
bool v[32];
int A[32],N;

void dfs(int dep) {
	if (dep > N) {
		if (prime[A[1] + A[N]]) {
			for (int i = 1;i < N;++ i) printf("%d ",A[i]);
			printf("%d\n",A[N]);
		}
		return;
	}
	for (int i = 1;i <= N;++ i)
		if ((!v[i]) && (prime[A[dep - 1] + i])) {
			A[dep] = i;
			v[i] = true;
			dfs(dep + 1);
			v[i] = false;
		}
}

int main() {

	memset(prime,0xff,sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2;i < 100;++ i)
		if (prime[i]) {
			for (int j = i + i;j < 100;j += i)
				prime[j] = false;
		}

    while (scanf("%d",&N) == 1) {
    	cn ++;
    	printf("Case %d:\n",cn);
    	memset(v,0,sizeof(v));
    	v[1] = true;
    	A[1] = 1;
    	dfs(2);
    	printf("\n");
    }
    
    return 0;
}
