#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char s[16384];
int sr[16384],sc[16384],R[16384],C[16384];
int n,l,top,ans;

char gt() {
	char ch = getchar();
	while (!isalpha(ch))
		ch = getchar();
	return ch;
}

bool getit() {
	l = 0;
	char ch = getchar();
	while ((ch != '(') && (ch != ')') && (!isalpha(ch)) && (ch != EOF))
		ch = getchar();
	if (ch == EOF) return false;
	while ((ch == '(') || (ch == ')') || (isalpha(ch))) {
		s[l ++] = ch;
		ch = getchar();
	}
	return true;
}

int main() {

	scanf("%d",&n);
	for (int i = 0;i < n;++ i) {
		char x = gt();
		scanf("%d%d",&R[x - 'A'],&C[x - 'A']);
	}
	while (getit()) {
		ans = 0;
		top = 0;
		bool err = false;
		int tr,tc;
		for (int i = 0;i < l;++ i) {
			if (isalpha(s[i])) {
				top ++;
				sr[top] = R[s[i] - 'A'];
				sc[top] = C[s[i] - 'A'];
				continue;
			}
			if (s[i] == ')') {
				if ((top < 2) || (sr[top] != sc[top - 1])) {
					err = true;
					break;
				}
				ans += (sc[top] * sr[top - 1] * sr[top]);
				tr = sr[top - 1];
				tc = sc[top];
				top --;
				sr[top] = tr;
				sc[top] = tc;
			}
		}
		if (err) puts("error");
		else printf("%d\n",ans);
	}

    return 0;
}