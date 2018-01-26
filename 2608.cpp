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

int t;
long long n;
int sum;

int main() {

    cin >> t;
    while (t --) {
        cin >> n;
        sum = 0;
        for (long long i = 1; (i*i) <= n; ++ i) {
            if (i*i <= n) sum ++;
            if (2*i*i <= n) sum ++;
        }
        cout << (sum%2) << endl;
    }

    return 0;
}