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

int n;

void solve(int ans) {
    for (int i = 1; i <= 100; ++ i)
        for (int j = 1; j <= 100; ++ j)
            if (i*i + j*j < ans) 
                for (int k = 1; k <= 100; ++ k)
                    if (i*i + j*j + k*k == ans) {
                        cout << i << " " << j << " " << k << endl;
                        return;
                    }
}

int main() {
    
    while (cin >> n) 
        solve(n);

    return 0;
}