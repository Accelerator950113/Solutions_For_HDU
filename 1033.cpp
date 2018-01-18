#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int dx[4] = {0,10,0,-10};
const int dy[4] = {10,0,-10,0};
const int nxta[4] = {1,2,3,0};
const int nxtv[4] = {3,0,1,2};
char s[16384];
int l,dir;
int x,y;

int main() {

	while (scanf("%s",s) == 1) {
		l = strlen(s);
		x = 310, y = 420, dir = 1;
		printf("300 420 moveto\n");
		printf("310 420 lineto\n");
		for (int i = 0;i < l;++ i) {
			if (s[i] == 'A') dir = nxta[dir];
			else dir = nxtv[dir];
			x += dx[dir], y += dy[dir];
			printf("%d %d lineto\n",x,y);
		}
		printf("stroke\n");
		printf("showpage\n");
	} 

    return 0;
}
