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

int T, N, ans;

int main() {

	cin >> T;
	while (T --) {
		cin >> N;
		ans = 0;
		while (N > 0) {
			ans += (N / 5);
			N /= 5;
		}
		cout << ans << endl;
	}

    return 0;
}
