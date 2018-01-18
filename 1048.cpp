#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

char s[16384];
int l;
int z[32];

int main() {

	for (int i = 0;i < 26;++ i)
		z[(i + 5) % 26] = i;

	while (gets(s)) {
		if (strcmp(s,"ENDOFINPUT") == 0) break;
		if (strcmp(s,"END") == 0) continue;
		if (strcmp(s,"START") == 0) {
			gets(s);
			l = strlen(s);
			for (int i = 0;i < l;++ i) 
				if ((s[i] >= 'A') && (s[i] <= 'Z')) s[i] = (char)('A' + z[s[i] - 'A']);
			puts(s);
		}
	} 

    return 0;
}
