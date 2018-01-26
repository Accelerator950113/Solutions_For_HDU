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

const char Code[29] = "_abcdefghijklmnopqrstuvwxyz.";

int key, l;
int cc[128], pc[128];
char ct[128];

int main() {

	while (scanf("%d", &key) != EOF) {
		if (key == 0) break;
		scanf("%s", ct);
		l = strlen(ct);
		for (int i = 0; i < l; ++ i)
			if (isalpha(ct[i])) cc[i] = ct[i] - 'a' + 1;
			else if (ct[i] == '_') cc[i] = 0;
			else cc[i] = 27;
		for (int i = 0; i < l; ++ i)
			pc[(key*i) % l] = (cc[i]+i) % 28;
		for (int i = 0; i < l; ++ i)
			putchar(Code[pc[i]]);
		putchar('\n');
	}

    return 0;
}
