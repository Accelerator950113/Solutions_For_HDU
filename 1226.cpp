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

using namespace std;

int Pre[8192];
int Cnt[8192];
int Dis[8192];
queue < int > Q;
char ch;
int n,c,m;
int a[32];

int get() {
	ch = getchar();
	while ((!isdigit(ch)) && (!isalpha(ch)))
		ch = getchar();
	if (isdigit(ch)) return (ch - '0');
	return (10 + ch - 'A');
}

void dy(int x) {
	if (x < 10) printf("%d",x);
	else putchar('A' + x - 10);
}

void output(int x) {
	if (x == -3) return;
	output(Pre[x]);
	dy(Cnt[x]);
}

int main() {

	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d",&n,&c);
		scanf("%d",&m);
		for (int i = 1;i <= m;++ i) 
			a[i] = get();
		sort(a + 1,a + m + 1);
		if (n == 0) {
			if (a[1] == 0) puts("0");
			else puts("give me the bomb please");
			continue;
		}
		memset(Pre,0xff,sizeof(Pre));
		memset(Dis,0,sizeof(Dis));
		while (!Q.empty())
			Q.pop();
		for (int i = 1;i <= m;++ i) 
			if ((a[i] != 0) && (Pre[a[i] % n] == -1)) {
				Pre[a[i] % n] = -3;
				Cnt[a[i] % n] = a[i];
				Dis[a[i] % n] = 1;
				Q.push(a[i] % n);
			}
		int tmp;
		while (!Q.empty()) {
			tmp = Q.front();
			Q.pop();
			for (int i = 1;i <= m;++ i)
				if (Pre[(tmp * c + a[i]) % n] == -1) {
					Pre[(tmp * c + a[i]) % n] = tmp;
					Cnt[(tmp * c + a[i]) % n] = a[i];
					Dis[(tmp * c + a[i]) % n] = Dis[tmp] + 1;
					Q.push((tmp * c + a[i]) % n);
				}
		}
		if ((Pre[0] == -1) || (Dis[0] > 500)) puts("give me the bomb please");
		else {
			output(0);
			putchar('\n');
		}
	}
    
    return 0;
}
