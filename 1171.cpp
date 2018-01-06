#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXM 131072

using namespace std;

const int c[8] = {1,2,4,8,16,32,64,128}; 
bool f[MAXM];
int n;
int v[512];
int sum;

int main() {

	int tmp,x,y;
	while ((scanf("%d",&tmp) == 1) && (tmp > 0)) {
		n = 0, sum = 0;
		while (tmp --) {
			scanf("%d%d",&x,&y);
			sum += (x * y);
			for (int i = 0;i < 8;++ i) 
				if (c[i] >= y) {
					v[++ n] = x * y;
					break;
				}
				else {
					y -= c[i];
					v[++ n] = x * c[i];
				}
		}
		memset(f,0,sizeof(f));
		f[0] = true;
		for (int i = 1;i <= n;++ i) 
			for (int j = sum;j >= v[i];-- j)
				f[j] |= f[j - v[i]];
		for (int i = (sum + 1) / 2;i <= sum;++ i)
			if (f[i]) {
				printf("%d %d\n",i,sum - i);
				break;
			}
	}
    
    return 0;
}
