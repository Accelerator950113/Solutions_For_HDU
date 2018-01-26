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
#define f(x) ((x) * (x))

using namespace std;

string s;

int main() {

	cin >> s;
	while (cin >> s) 
		cout << "6" + s.substr(s.size() - 5, 5) << endl;

    return 0;
}
