#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n;

int main() {

	while (scanf("%d",&n) == 1) {
		int ok = -1;
		for (int i = 1;i < 65;++ i) 
			if (((i*n) % 5 == 2) && ((i*n) % 13 == 8)) {
				ok = i;
				break;
			}
		if (ok == -1) puts("no");
		else printf("%d\n",ok);
	}

    return 0;
}
