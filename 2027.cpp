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

int f[128];
string s;
bool fst = true;

int main() {

	getline(cin, s);
	while (getline(cin, s)) {
		memset(f, 0, sizeof(f));
		for (int i = 0; i < s.size(); ++ i)
			if (isalpha(s[i])) f[s[i] - 'A'] ++;
		if (fst) fst = false;
		else cout << endl;
		cout << "a:" << f['a' - 'A'] << endl;
		cout << "e:" << f['e' - 'A'] << endl;
		cout << "i:" << f['i' - 'A'] << endl;
		cout << "o:" << f['o' - 'A'] << endl;
		cout << "u:" << f['u' - 'A'] << endl;
	}

    return 0;
}
