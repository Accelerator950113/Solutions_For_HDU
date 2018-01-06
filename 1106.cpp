#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char s[2048];
int a[2048];

int main() {

	while (gets(s)) {
		bool you = false;
		int n = 0, ts = 0;
		int l = strlen(s);
		for (int i = 0;i < l;++ i) {
			if ((s[i] < '0') || (s[i] > '9') || (s[i] == '5')) {
				if (you) {
					a[n ++] = ts;
					you = false;
				}
				ts = 0;
				continue;
			} 
			you = true;
			ts = ts * 10 + (s[i] - '0');
		}
		if (you) a[n ++] = ts;
		sort(a, a + n);
		if (n > 0) {
			printf("%d",a[0]);
			for (int i = 1;i < n;++ i) 
				printf(" %d",a[i]);
		}
		printf("\n");
	}
    
    return 0;
}
