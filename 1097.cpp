#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#define LL long long

using namespace std;

LL a,b;

LL cf(LL x,LL y) {
    if (y == 1ll) return x % 10ll;
    LL tmp = cf(x,y / 2ll);
    tmp = (tmp * tmp) % 10ll;
    if (y & 1ll) tmp = (tmp * x) % 10ll;
    return tmp;
}

int main() {

	while (cin >> a >> b)
        cout << cf(a,b) << endl;

    return 0;
}
