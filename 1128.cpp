#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXM 1000000

using namespace std;

bool f[1048576];
int s,t,xx;

int d(int x) {
	s = 0,t = x;
	while (t > 0) {
		s = s + (t % 10);
		t /= 10;
	}
	return (x + s);
}

int main() {

	memset(f,0xff,sizeof(f));
	for (int i = 1;i <= MAXM;++ i) 
		if (f[i]) {
			xx = d(i);
			while ((xx <= MAXM) && (f[xx])) {
				f[xx] = false;
				xx = d(xx);
			}
		}
	for (int i = 1;i <= MAXM;++ i)
		if (f[i]) printf("%d\n",i);
    
    return 0;
}
