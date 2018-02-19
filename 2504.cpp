#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int T, a, b, c;

int gcd(int x, int y) {
	if (x % y == 0)
		return y;
	else
		return gcd(y, x % y);
}

int main() {
    
    cin >> T;
    while (T --) {
    	cin >> a >> b;
    	c = b+b;
    	while (gcd(a, c) != b)
    		c += b;
    	cout << c << endl;
    }

    return 0;
}