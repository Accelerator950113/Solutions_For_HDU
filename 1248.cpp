#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

bool f[16384];
int ans[16384];

int main() {

	memset(f,0,sizeof(f));
	f[0] = true;
	for (int i = 0;i <= 10000;++ i)
		if (f[i]) {
			f[i + 150] = true;
			f[i + 200] = true;
			f[i + 350] = true;
		}
	ans[0] = 0;
	for (int i = 1;i <= 10000;++ i)
		if (f[i]) ans[i] = 0;
		else ans[i] = ans[i - 1] + 1;

	int n,t;
	cin >> t;
	while (t --) {
		cin >> n;
		cout << ans[n] << endl;
	}


    return 0;
}
