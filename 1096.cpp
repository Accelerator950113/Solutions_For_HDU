#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T,n;
long long s,x;

int main() {

    cin >> T;
    while (T --) {
    	cin >> n;
    	s = 0ll;
    	while (n --) {
    		cin >> x;
    		s = s + x;
    	}
    	cout << s << endl;
    	if (T > 0) cout << endl;
    }
    
    return 0;
}
