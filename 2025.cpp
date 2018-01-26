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

string s;

int main() {

	while (cin >> s) {
		int id = 0;
		for (int i = 1; i < s.size(); ++ i)
			if (s[i] > s[id]) id = i;
		for (int i = 0; i < s.size(); ++ i)
			if (s[i] == s[id]) cout << s[i] << "(max)";
			else cout << s[i];
		cout << endl;
	}

    return 0;
}
