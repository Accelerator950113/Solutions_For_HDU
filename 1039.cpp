#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char s[8192];
bool vol[8192];
int l;

bool volwel(char x) {
	return ((x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x == 'u'));
}

int main() {

	while (scanf("%s",s) != EOF) {
		if (strcmp(s,"end") == 0) break;
		l = strlen(s);
		for (int i = 0;i < l;++ i)
			vol[i] = volwel(s[i]);
		bool ok = false;
		for (int i = 0;i < l;++ i)
			ok |= vol[i];
		bool ok2 = true;
		for (int i = 0;i+2 < l;++ i)
			if ((vol[i] == vol[i+1]) && (vol[i+1] == vol[i+2])) {
				ok2 = false;
				break;
			}
		bool ok3 = true;
		for (int i = 0;i+1 < l;++ i)
			if ((s[i] == s[i+1]) && (s[i] != 'e') && (s[i] != 'o')) {
				ok3 = false;
				break;
			}
		if (ok && ok2 && ok3) printf("<%s> is acceptable.\n",s);
		else printf("<%s> is not acceptable.\n",s);
	}

    return 0;
}