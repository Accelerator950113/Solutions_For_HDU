#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char s[1024];
bool g[32][32];
bool v[32];

void dfs(int x) {
	v[x] = true;
	for (int i = 0;i < 24;++ i)
		if ((!v[i]) && (g[x][i])) dfs(i);
}

int main() {

	while (gets(s)) {

		memset(g,0,sizeof(g));
		memset(v,0,sizeof(v));

		while (s[0] != '0') {
			g[s[0] - 'a'][s[strlen(s) - 1] - 'a'] = true;
			gets(s);
		}

		dfs('b' - 'a');

		if (v['m' - 'a']) printf("Yes.\n");
		else printf("No.\n");
    
    }

    return 0;
}
