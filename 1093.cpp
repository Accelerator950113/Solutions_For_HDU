#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
long long s,x;

int main() {

    cin >> n;
    while (cin >> n) { 
        if (n == 0) break;
        s = 0ll;
        while (n --) {
        	cin >> x;
        	s = s + x;
        }
        cout << s << endl;
    }
    
    return 0;
}
