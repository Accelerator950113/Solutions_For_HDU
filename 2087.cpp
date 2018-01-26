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
#include <sstream>

using namespace std;

string s1, s2;
size_t pos;
int ans;

int main() {

	while (cin >> s1 >> s2) {
		ans = 0;
		pos = s1.find(s2);
		while (pos != string::npos) {
			ans ++;
			s1.erase(pos, s2.size());
			pos = s1.find(s2);
		}
		cout << ans << endl;
	}

    return 0;
}
