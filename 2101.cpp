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

long long a, b;

int main() {

	while (cin >> a >> b)
		cout << (((a+b)%86 == 0) ? ("yes") : ("no")) << endl;

    return 0;
}
