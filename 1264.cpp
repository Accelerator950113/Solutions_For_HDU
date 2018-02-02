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

int ans;
int f[128][128];
int x[2], y[2];

void Initialize() {
    for (int i = 0; i < 100; ++ i)
        for (int j = 0; j <= 100; ++ j)
            f[i][j] = j;
    ans = 0;
}

int Find(int id, int x) {
    if (f[id][x] != x) 
        f[id][x] = Find(id, f[id][x]);
    return f[id][x];
}

void Delete(int id, int s, int t) {
    for (int i = Find(id, s); i <= t; i = Find(id, i+1)) {
        ans ++;
        f[id][i] = f[id][t+1];
    }
}

int main() {
    
    while (true) {
        Initialize();
        while (true) {
            cin >> x[0] >> y[0] >> x[1] >> y[1];
            if (x[0] < 0) 
                break;
            if (x[0] > x[1])
                swap(x[0], x[1]);
            if (y[0] > y[1])
                swap(y[0], y[1]);
            -- x[1], --y[1];
            for (int i = x[0]; i <= x[1]; ++ i)
                Delete(i, y[0], y[1]);
        }
        cout << ans << endl;
        if (x[0] == -2) break;
    }

    return 0;
}