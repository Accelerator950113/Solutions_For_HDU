#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <sstream>

using namespace std;

string s[128], tmp, tmp2;
int T, n;
int ans;
size_t tp, tp2;

bool check() {
    for (int i = 0; i < n; ++ i) {
        tp = s[i].find(tmp);
        tp2 = s[i].find(tmp2);
        if ((tp == string::npos) && (tp2 == string::npos)) return false;
    }
    return true;
}

int main() {

    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; ++ i)
            cin >> s[i];
        ans = 0;
        for (int i = 0; i < s[1].size(); ++ i) {
            tmp = "";
            for (int j = i; j < s[1].size(); ++ j) {
                tmp = tmp + s[1][j];
                tmp2 = tmp;
                reverse(tmp.begin(), tmp.end());
                if (check()) ans = max(ans, j-i+1);
                tmp = tmp2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}