#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char s[8192];
char s1[2048],s2[2048];
int f[2048][2048];

int main() {

	while (gets(s)) {
		int tt = 0;
		while (s[tt] != ' ') 
			tt ++;
		strncpy(s1, s, tt);
		s1[tt] = '\0';
		while (s[tt] == ' ')
			tt ++;
		strncpy(s2, s + tt, strlen(s) - tt + 1);
		s2[strlen(s) - tt + 1] = '\0';
		int n1 = strlen(s1);
		int n2 = strlen(s2);
		memset(f,0x80,sizeof(f));
		for (int i = 0;i <= n1;++ i)
			f[i][0] = 0;
		for (int j = 0;j <= n2;++ j)
			f[0][j] = 0;
		for (int i = 1;i <= n1;++ i)
			for (int j = 1;j <= n2;++ j) {
				if (s1[i - 1] == s2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
				if (f[i - 1][j] > f[i][j]) f[i][j] = f[i - 1][j];
				if (f[i][j - 1] > f[i][j]) f[i][j] = f[i][j - 1];
			}
		printf("%d\n",f[n1][n2]);
	}
    
    return 0;
}
