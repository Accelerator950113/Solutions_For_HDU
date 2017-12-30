#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int n,a[16384];
int ans;

int gcd(int x,int y) {
	if ((x % y) == 0) return y;
	else return gcd(y,x % y);
}

int main() {

	scanf("%d",&N);
    while (N --) {
        scanf("%d",&n);
        for (int i = 1;i <= n;++ i) scanf("%d",a + i);
        sort(a + 1,a + n + 1);
    	for (int i = 1;i < n;++ i)
    		if (a[i] != 1) 
    			for (int j = i + 1;j <= n;++ j)
    				a[j] = a[j] / gcd(a[j],a[i]);
    	ans = 1;
    	for (int i = 1;i <= n;++ i)
    		ans = ans * a[i];
    	printf("%d\n",ans);
    }
    
    return 0;
}
