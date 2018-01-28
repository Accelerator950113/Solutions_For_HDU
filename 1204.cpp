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
#include <bitset>
#include <sstream>

using namespace std;

int n, m;
int N;
double p, q;
double p1, p2, p3;
double a[128][128], b[128][128];

void show() {
	for (int i = 0; i <= N; ++ i) {
		for (int j = 0; j <= N; ++ j)
			printf("%.2lf ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {

	while (scanf("%d%d%lf%lf", &n, &m, &p, &q) == 4) {
		if (n == 0) {
			puts("0.00");
			continue;
		}
		if (m == 0) {
			puts("1.00");
			continue;
		}
		p1 = p - p*q;
		p2 = q - p*q;
		p3 = 1 - p - q + 2*p*q;
		N = n+m;
		for (int i = 0; i <= N; ++ i)
			for (int j = 0; j <= N; ++ j)
				a[i][j] = 0;
		for (int i = 2; i <= N-2; ++ i)
			a[i-1][i] = p1, a[i][i] = p3, a[i+1][i] = p2;
		a[1][0] = p2;
		a[2][1] = p2, a[1][1] = p3;
		a[N-1][N] = p1;
		a[N-2][N-1] = p1, a[N-1][N-1] = p3;
		a[0][0] = 1, a[N][N] = 1;
		if (N == 2) 
			a[2][1] = a[0][1] = 0;
		//show();
		for (int cs = 0; cs < 32; ++ cs) {
			for (int i = 0; i <= N; ++ i)
				for (int j = 0; j <= N; ++ j) {
					b[i][j] = 0;
					for (int k = 0; k <= N; ++ k)
						b[i][j] += (a[i][k] * a[k][j]);
				}
			for (int i = 0; i <= N; ++ i)
				for (int j = 0; j <= N; ++ j)
					a[i][j] = b[i][j];
		}
		//show();
		printf("%.2lf\n", a[n][N]);
	}

    return 0;
}