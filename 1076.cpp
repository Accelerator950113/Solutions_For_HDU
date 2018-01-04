#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int ans[16384];
int T;
int x,y;

bool pan(int x) {
    if ((x % 400) == 0) return true;
    return (((x % 100) != 0) && ((x % 4) == 0));
}

int nxt(int n) {
    int nn = n + 4;
    while (!pan(nn)) nn += 4;
    return nn;
}

int main() {

    ans[0] = 0;
    for (int i = 1, cnt = 0;i <= 10000;++ i) {
        cnt += 4;
        while (!pan(cnt)) cnt += 4;
        ans[i] = cnt;
    }

    cin >> T;
    while (T --) {
        cin >> x >> y;
        while (!pan(x)) x ++;
        y --;
        while (((x % 100) != 0) && (y > 0)) {
            x = nxt(x);
            y --;
        }
        cout << x + ans[y] << endl;
    }
    
    return 0;
}
