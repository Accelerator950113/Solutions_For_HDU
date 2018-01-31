#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > g[512];
vector < int > ans;
int rd[512];
bool v[512];
int x, y, n, m;

int main() {

    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++ i) {
            g[i].clear();
            rd[i] = 0;
            v[i] = false;
        }
        while (m --) {
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            rd[y] ++;
        }
        ans.clear();
        for (int i = 0;i < n; ++ i) {
            x = 1;
            while ((v[x]) || (rd[x] != 0))
                ++ x;
            ans.push_back(x);
            v[x] = true;
            for (int j = 0; j < g[x].size(); ++ j)
                rd[g[x][j]] --;
        }
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); ++ i)
            printf(" %d", ans[i]);
        printf("\n");
    }

    return 0;
}