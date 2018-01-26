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
#define PI 3.14159265

using namespace std;

int n;
int s1, s2, s3;

int main() {

	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		s1 = (n%10) + ((n%100)/10) + ((n%1000)/100) + (n/1000);
		s2 = (n%16) + ((n%256)/16) + ((n%4096)/256) + (n/4096);
		s3 = (n%12) + ((n%144)/12) + ((n%1728)/144) + (n/1728);
		if ((s1 == s2) && (s2 == s3)) printf("%d is a Sky Number.\n", n);
		else printf("%d is not a Sky Number.\n", n);
	}

    return 0;
}
