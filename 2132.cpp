#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long s[131072];
int n;

int main() {

    s[0] = 0;
    for (int i = 1; i <= 100000; ++ i)
        if (i % 3 == 0) 
            s[i] = s[i-1] + (long long)i*i*i;
        else 
            s[i] = s[i-1] + i;

    while (cin >> n) 
        if (n < 0) 
            break;
        else 
            cout << s[n] << endl;

    return 0;
}