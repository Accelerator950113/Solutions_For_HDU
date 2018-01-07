#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int s1,s2,s3;

int main() {

	for (int i = 1000;i <= 9999;++ i) {
		s1 = (i % 10) + ((i % 100) / 10) + ((i % 1000) / 100) + (i / 1000);
		s2 = (i % 16) + ((i % 256) / 16) + ((i % 4096) / 256) + (i / 4096);
		s3 = (i % 12) + ((i % 144) / 12) + ((i % 1728) / 144) + (i / 1728);
		if ((s1 == s2) && (s2 == s3)) printf("%d\n",i);
	}

    return 0;
}
