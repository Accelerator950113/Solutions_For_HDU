#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;

int gcd(int x,int y) {
    if ((x % y) == 0) return y;
    else return gcd(y,x % y);
}

int main() {

    while (cin >> n >> m) 
        cout << n * m / gcd(n,m) << endl;
    
    return 0;
}
