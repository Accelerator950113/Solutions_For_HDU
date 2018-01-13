#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char s[1024];
int a[2048];
int n;

bool allzero(int x,int y) {
	for (int i = x;i <= y;++ i)
		if (a[i] != 0) return false;
	return true;
}

int main() {

	while (scanf("%s%d",s,&n) != EOF) {
		int l = strlen(s),count = 0;
		bool xiao = false;
		int tmp = 0;
		for (int i = 0;i < l;++ i) 
			if (s[i] == '.') {
				xiao = true;
			}
			else {
				tmp = tmp * 10 + (s[i] -'0');
				if (xiao) count ++;
			}
		count *= n;
		memset(a,0,sizeof(a));
		a[1] = 1;
		for (int i = 0;i < n;++ i) {
			for (int j = 1;j <= 1000;++ j)
				a[j] *= tmp;
			for (int j = 1;j <= 1000;++ j) {
				a[j + 1] += (a[j] / 10);
				a[j] %= 10;
			}
		}
		if (allzero(1,count)) {
			if (allzero(count + 1,1000)) puts("0");
			else {
				int tou = 1000;
				while (a[tou] == 0) tou --;
				for (int i = tou;i > count;-- i)
					printf("%d",a[i]);
				printf("\n");
			}
		}
		else {
			if (!allzero(count + 1,1000)) {
				int tou = 1000;
				while (a[tou] == 0) tou --;
				for (int i = tou;i > count;-- i)
					printf("%d",a[i]);
			}
			putchar('.');
			int wei = 1;
			while (a[wei] == 0) wei ++;
			for (int i = count;i >= wei;-- i)
				printf("%d",a[i]);
			putchar('\n');
		}
	}

    return 0;
}