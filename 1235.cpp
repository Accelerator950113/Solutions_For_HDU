#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n,a[2048],x,ans;

int main() {

	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		for (int i = 0;i < n;++ i) 
			scanf("%d",&a[i]);
		scanf("%d",&x);
		ans = 0;
		for (int i = 0;i < n;++ i) 
			if (a[i] == x) ans ++;
		cout << ans << endl;
	}

    return 0;
}
