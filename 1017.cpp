#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int N,n,m;
int ans;

int main() {

	scanf("%d",&N);
    while (N --) {
    	for (int cst = 1;scanf("%d%d",&n,&m) == 2;++ cst) {
    		if ((n == 0) && (m == 0)) break;
    		ans = 0;
    		for (int a = 1;a < n;++ a)
    			for (int b = a + 1;b < n;++ b)
    				if (((a * a + b * b + m) % (a * b)) == 0) ans ++;
    		printf("Case %d: %d\n",cst,ans);
    	}
    	if (N > 0) printf("\n");
    }
    
    return 0;
}
