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
#include <set>

using namespace std;

int n,m;
int score[1024][1024];
int ansx, ansy;

int main() {

	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j)
				scanf("%d", &score[i][j]);
		ansx = 1, ansy = 1;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j)
				if (abs(score[i][j]) > abs(score[ansx][ansy])) 
					ansx = i, ansy = j;
		printf("%d %d %d\n", ansx, ansy, score[ansx][ansy]);
	}

    return 0;
}
