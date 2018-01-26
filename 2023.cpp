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
int score[64][8];
int ans;

int main() {

	while (scanf("%d%d", &n, &m) != EOF) {
		memset(score, 0, sizeof(score));
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j)
				scanf("%d", &score[i][j]);
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j)
				score[i][0] += score[i][j];
		for (int i = 1; i <= m; ++ i)
			for (int j = 1; j <= n; ++ j)
				score[0][i] += score[j][i];
		ans = 0;
		bool flag;
		for (int i = 1; i <= n; ++ i) {
			flag = true;
			for (int j = 1; j <= m; ++ j)
				if (score[i][j] * n < score[0][j]) flag = false;
			if (flag) ans ++;
		}
		printf("%.2lf", (double)score[1][0] / m);
		for (int i = 2; i <= n; ++ i)
			printf(" %.2lf", (double)score[i][0] / m);
		printf("\n");
		printf("%.2lf", (double)score[0][1] / n);
		for (int i = 2; i <= m; ++ i)
			printf(" %.2lf", (double)score[0][i] / n);
		printf("\n");
		printf("%d\n", ans);
		printf("\n");
	}

    return 0;
}
