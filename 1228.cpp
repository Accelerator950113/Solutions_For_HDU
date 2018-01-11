#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

char s[1024];

int getnum(int p) {
	if ((s[p] == 'z') && (s[p + 1] == 'e')) return 0;
	if ((s[p] == 'o') && (s[p + 1] == 'n')) return 1;
	if ((s[p] == 't') && (s[p + 1] == 'w')) return 2;
	if ((s[p] == 't') && (s[p + 1] == 'h')) return 3;
	if ((s[p] == 'f') && (s[p + 1] == 'o')) return 4;
	if ((s[p] == 'f') && (s[p + 1] == 'i')) return 5;
	if ((s[p] == 's') && (s[p + 1] == 'i')) return 6;
	if ((s[p] == 's') && (s[p + 1] == 'e')) return 7;
	if ((s[p] == 'e') && (s[p + 1] == 'i')) return 8;
	return 9;
}

int main() {

    while (gets(s)) {
        int p = 0;
        int a = 0;
        int ta;
        while ((s[p] >= 'a') && (s[p] <= 'z')) {
        	ta = getnum(p);
        	a = a * 10 + ta;
        	while (s[p] != ' ') p ++;
        	p ++;
        }
        p += 2;
        int b = 0;
        while ((s[p] >= 'a') && (s[p] <= 'z')) {
        	ta = getnum(p);
        	b = b * 10 + ta;
        	while (s[p] != ' ') p ++;
        	p ++;
        }
        if ((a == 0) && (b == 0)) break;
        printf("%d\n",a + b);
    }
    
    return 0;
}
