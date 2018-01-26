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

int n;
string s;
int s1, s2, s3, s4;
int ans;

bool isSpecial(char x) {
	return ((x == '^') || (x == '!') || (x == '@')
		|| (x == '#') || (x == '$') || (x == '~') || (x == '%'));
}

int main() {

	cin >> n;
	while (n --) {
		cin >> s;
		s1 = s2 = s3 = s4 = 0;
		for (int i = 0; i < s.size(); ++ i) {
			if (('a' <= s[i]) && (s[i] <= 'z')) s1 ++;
			if (('A' <= s[i]) && (s[i] <= 'Z')) s2 ++;
			if (isdigit(s[i])) s3 ++;
			if (isSpecial(s[i])) s4 ++;
		}
		ans = 0;
		if (s1 > 0) ans ++;
		if (s2 > 0) ans ++;
		if (s3 > 0) ans ++;
		if (s4 > 0) ans ++;
		if ((s.size() < 8) || (s.size() > 16)) ans = 0;
		cout << ((ans >= 3) ? ("YES") : ("NO")) << endl;
	}

    return 0;
}
