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

using namespace std;

int n;
bool f[1024];
int sum[1048576];

int main() {

	memset(f, 0, sizeof(f));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= 500000; ++ i)
		for (int j = i+i; j <= 1000000; j += i)
			sum[j] += i;
	for (int i = 1; i <= 1000000; ++ i)
		if (sum[i] <= 1000) f[sum[i]] = true;

	cin >> n;
	while (cin >> n) 
		cout << ((!f[n]) ? ("yes") : ("no")) << endl;

    return 0;
}
