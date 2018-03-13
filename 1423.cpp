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
#include <set>
#include <algorithm>

using namespace std;

int T;
int n, m;
int a[512], b[512];
int bh[512], f[512][512];
int ans;

int main() {
    
    ios::sync_with_stdio(false);
    
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i)
            cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; ++ i)
            cin >> b[i];
        memset(bh, 0xff, sizeof(bh));
        bh[0] = 0;
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= m; ++ j)
                if (a[i] == b[j]) {
                    bh[i] = j;
                    break;
                }
        }
        memset(f, 0x80, sizeof(f));
        f[0][0] = 0;
        ans = 0;
        for (int i = 1; i <= n; ++ i) {
            if (bh[i] == -1)
                continue;
            for (int j = 0; j < n; ++ j)
                if ((a[j] < a[i]) && (bh[j] != -1) && (bh[j] < bh[i]))
                    f[i][bh[i]] = max(f[i][bh[i]], f[j][bh[j]] + 1);
            ans = max(ans, f[i][bh[i]]);
        }
        cout << ans << endl;
        if (T != 0)
            cout << endl;
    }

    return 0;
}