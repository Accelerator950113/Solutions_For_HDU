#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#define left(x) ((x-1)*(x-1) + 1)
#define right(x) ((x) * (x))

using namespace std;

int n,m;

int main() {

    while (cin >> n >> m) {
        if (n > m) {
            n = n ^ m;
            m = n ^ m;
            n = n ^ m;
        }
        int cn = (int)ceil(sqrt(n));
        int cm = (int)ceil(sqrt(m));
        int zuo = n - left(cn);
        int you = n - right(cn);
        zuo += left(cm);
        you += right(cm);
        if (m <= zuo) {
            cout << (zuo - m + 2*(cm-cn)) << endl;
            continue;
        }
        if (m >= you) {
            cout << (m - you + 2*(cm-cn)) << endl;
            continue;
        }
        bool isupn = ((n & 1) == (cn & 1));
        bool isupm = ((m & 1) == (cm & 1));
        if (isupn == isupm) {
            cout << 2*(cm-cn) << endl;
        }
        else {
            if (!isupn) {
                cout << 2*(cm-cn)+1 << endl;
            }
            else {
                cout << 2*(cm-cn)-1 << endl;
            }
        }
    }
    
    return 0;
}
