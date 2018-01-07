#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define getmin(x,y) ((x < y) ? (x) : (y))

using namespace std;

int N;
int A[128],B[128],C[128];
int F1[128][8],F2[128][16];
int total, first;
int a[8],b[16];

bool cmp1(int x) {
	int ts = 0;
	for (int t = 0;t < 4;++ t)
		if (F1[x][t] == a[t]) ts ++;
	return (ts == C[x]);
}

bool cmp2(int x) {
	int ts = 0;
	for (int t = 0;t < 10;++ t)
		ts += getmin(F2[x][t],b[t]);
	return (ts == B[x]);
}

bool check(int x) {
	a[0] = x % 10;
	a[1] = (x % 100) / 10;
	a[2] = (x % 1000) / 100;
	a[3] = x / 1000;
	memset(b,0,sizeof(b));
	b[a[0]] ++;
	b[a[1]] ++;
	b[a[2]] ++;
	b[a[3]] ++;
	for (int i = 1;i <= N;++ i) {
		if (!cmp1(i)) return false;
		if (!cmp2(i)) return false;
	}
	return true;
}

int main() {

	while ((scanf("%d",&N) == 1) && (N != 0)) {
		memset(F2,0,sizeof(F2));
		for (int i = 1;i <= N;++ i) {
			scanf("%d%d%d",A + i,B + i,C + i);
			a[0] = A[i] % 10;
			a[1] = (A[i] % 100) / 10;
			a[2] = (A[i] % 1000) / 100;
			a[3] = A[i] / 1000;
			sort(b,b + 4);
			for (int j = 0;j < 4;++ j) {
				F1[i][j] = a[j];
				F2[i][a[j]] ++;
			}
		}
		total = 0;
		for (int i = 1000;i <= 9999;++ i)
			if (check(i)) {
				total ++;
				first = i;
				if (total == 2) break;
			}
		if (total != 1) printf("Not sure\n");
		else printf("%d\n",first);
	}

    return 0;
}
