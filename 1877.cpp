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

int m;
long long a, b;

void print(long long x) {
    if (x == 0)
        return;
    print(x / m);
    cout << x % m;
}

int main() {
    
    while (cin >> m) {
        if (m == 0)
            break;
        cin >> a >> b;
        print((a+b) / m);
        cout << (a+b) % m << endl;
    } 

    return 0;
}