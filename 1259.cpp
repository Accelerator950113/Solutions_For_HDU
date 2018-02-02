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

string s;
int T, n, x, y;

int main() {
    
    cin >> T;
    while (T --) {
        cin >> n;
        s = " ZJUTACM";
        while (n --) {
            cin >> x >> y;
            swap(s[x], s[y]);
        }
        for (int i = 1; i <= 7; ++ i)
            if (s[i] == 'J') {
                cout << i << endl;
                break;
            }
    }

    return 0;
}