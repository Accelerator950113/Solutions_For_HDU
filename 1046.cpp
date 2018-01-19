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

int n,m;
double ans;
int T;

int main() {

	scanf("%d",&T);
	for (int i = 1;i <= T;++ i) {
		scanf("%d%d",&n,&m);
		if ((n&1) && (m&1)) ans = n*m-1 + sqrt(2);
		else ans = n*m;
		printf("Scenario #%d:\n%.2lf\n\n",i,ans);
	}
    
    return 0;
}
