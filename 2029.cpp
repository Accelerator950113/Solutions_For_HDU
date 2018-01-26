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
string s1, s2;

int main() {

	cin >> n;
	while (n --) {
		cin >> s1;
		s2 = s1;
		reverse(s2.begin(), s2.end());
		cout << ((s1.compare(s2) == 0) ? ("yes") : ("no")) << endl;
	}

    return 0;
}
