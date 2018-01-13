#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char s[1048576];
int b;

int main() {

	while (scanf("%s%d",s,&b) != EOF) {
		int l = strlen(s);
		int rest = 0;
		for (int i = 0;i < l;++ i) 
			rest = (rest * 10 + (s[i] - '0')) % b;
		printf("%d\n",rest);
	}

    return 0;
}