#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

string buf, ck;

int main() {
    
    while (getline(cin, ck)) {
        if (ck == "#")
            break;
        getline(cin, buf);
        int ans;
        for (int i = 0; i < ck.size(); ++ i) {
            ans = 0;
            for (int j = 0; j < buf.size(); ++ j)
                if (ck[i] == buf[j])
                    ans ++;
            cout << ck[i] << " " << ans << endl;
        }
    }

    return 0;
}