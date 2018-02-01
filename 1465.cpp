#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long d[32];
int n;

int main() {

    d[1] = 0;
    d[2] = 1;
    for (int i = 3; i <= 20; ++ i)
        d[i] = (long long)(i-1) * (d[i-1] + d[i-2]);

    while (cin >> n) 
        cout << d[n] << endl;

    return 0;
}