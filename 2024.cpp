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
bool flag;

int main() {

	getline(cin, s);
	while (getline(cin, s)) {
		flag = true;
		for (int i = 0; i < s.size(); ++ i)
			if ((!isdigit(s[i])) && (!isalpha(s[i])) && (s[i] != '_')) {
				flag = false;
				break;
			}
		if (isdigit(s[0])) flag = false;
		cout << ((flag) ? ("yes") : ("no")) << endl;
	}

    return 0;
}
