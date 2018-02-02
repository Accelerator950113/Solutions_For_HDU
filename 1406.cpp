#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int f[16384];
int s[16384];
int a, b;

int main() {
    
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= 10000; ++ i)
        for (int j = i+i; j <= 10000; j += i)
            f[j] += i;
    s[0] = s[1] = 0;
    for (int i = 2; i <= 10000; ++ i)
        if (f[i] == i) s[i] = s[i-1] + 1;
        else s[i] = s[i-1];

    cin >> a;
    while (cin >> a >> b) 
        cout << s[max(a, b)] - s[min(a, b)-1] << endl;

    return 0;
}