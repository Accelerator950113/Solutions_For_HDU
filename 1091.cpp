#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long a,b;

int main() {

    while (cin >> a >> b) { 
        if ((a == 0ll) && (b == 0ll)) break;
        cout << a + b << endl;
    }
    
    return 0;
}
