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

int Eular(int n) {
    int ret = n;
    for (int i = 2; i*i <= n; ++ i)
        if (n%i == 0) {
            ret = ret/i * (i-1);
            while (n%i == 0)
                n /= i;
        }
    if (n > 1) 
        ret = ret/n * (n-1);
    return ret;
}

int main() {
    
    int T, n;
    cin >> T;
    while (T --) {
        cin >> n;
        cout << Eular(n) << endl;
    }

    return 0;
}