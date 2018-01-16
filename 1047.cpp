#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char s[512];
int a[512];
int T,l;

void getit() {
	l = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch)) {
		s[l ++] = ch;
		ch = getchar();
	}
	s[l] = '\0';
}

int main() {

	scanf("%d",&T);
	while (T --) {
		memset(a,0,sizeof(a));
		while (true) {
			getit();
			if (strcmp(s,"0") == 0) break;
			reverse(s,s+l);
			for (int i = 0;i < l;++ i) 
				a[i + 1] += (s[i] -'0');
			for (int i = 1;i <= l;++ i) {
				a[i + 1] += (a[i] / 10);
				a[i] %= 10;
			}
		}
		int tou = 500;
		while ((a[tou] == 0) && (tou > 1)) 
			tou --;
		for (int i = tou;i > 0;-- i)
			printf("%d",a[i]);
		printf("\n");
		if (T != 0) printf("\n");
	}

    return 0;
}