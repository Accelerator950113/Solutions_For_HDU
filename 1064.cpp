#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

double x,ans;

int main() {

	ans = 0;
    for (int i = 0;i < 12;++ i) {
    	cin >> x;
    	ans += x;
    }
    cout << '$' << ans/12 << endl;

    return 0;
}