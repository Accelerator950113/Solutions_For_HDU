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

int n;

int main() {
    
    while (cin >> n) {
        cout << (n*n*n * (n*n*n - 1)) / 2 - 3 * (n*n) * (n-1) << endl;
    }

    return 0;
}