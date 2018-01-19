#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool check(int a,int b,int k) {
	for (int i = 0;i < k;++ i) {
		if ((a % 10) != (b % 10)) return false;
		a /= 10;
		b /= 10;
	}
	return true;
}

int main() {

	int a,b,k;
	while (cin >> a >> b >> k) {
		if ((a == 0) && (b == 0)) break;
		if (check(a,b,k)) cout << "-1" << endl;
		else cout << a + b << endl;
	}
    
    return 0;
}
