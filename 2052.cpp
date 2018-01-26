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

using namespace std;

int n, m;

void printLine() {
	putchar('+');
	for (int i = 1; i <= n; ++ i)
		putchar('-');
	putchar('+');
	putchar('\n');
}

void printMiddle() {
	putchar('|');
	for (int i = 1; i <= n; ++ i)
		putchar(' ');
	putchar('|');
	putchar('\n');
}

int main() {

	while (scanf("%d%d", &n ,&m) != EOF) {
		printLine();
		for (int i = 1; i <= m; ++ i)
			printMiddle();
		printLine();
		putchar('\n');
	}

    return 0;
}
