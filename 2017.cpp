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

int t;
string s;

int main() {

	cin >> t;
	while (t --) {
		cin >> s;
		int ans = 0;
		for (int i = 0; i < s.size(); ++ i)
			if (isdigit(s[i])) ans ++;
		cout << ans << endl;
	}

    return 0;
}
