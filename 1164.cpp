#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n;

int main() {

	while (cin >> n) {
		bool fst = true;
		for (int i = 2;i*i <= n;++ i) {
			while ((n % i) == 0) {
				if (fst) {
					printf("%d",i);
					fst = false;
				}
				else printf("*%d",i);
				n /= i;
			}
		}
		if (n != 1) {
			if (!fst) putchar('*');
			printf("%d",n); 
		}
		printf("\n");
	}

    return 0;
}
