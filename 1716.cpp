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

class Printer {
    private:
        bool space, spaceLine;
    public:
        void Start() {
            spaceLine = false;
        }
        void NextCase() {
            if (spaceLine)
                printf("\n");
            else
                spaceLine = true;
        }
        void Init() {
            space = false;
        }
        void NewLine() {
            printf("\n");
            space = false;
        }
        void Print(int x) {
            if (space)
                printf(" ");
            else
                space = true;
            printf("%d", x);
        }
};

vector < int > ans;
int a[8];
bool v[8];
Printer pr;

void Dfs(int dep, int cnt) {
    if (dep > 4) {
        if (cnt >= 1000) 
            ans.push_back(cnt);
        return;
    }
    for (int i = 1; i <= 4; ++ i)
        if (!v[i]) {
            v[i] = true;
            Dfs(dep+1, cnt*10+a[i]);
            v[i] = false;
        }
}

int main() {
    
    pr.Start();
    while (scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]) == 4) {
        if (a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0)
            break;
        pr.NextCase();
        ans.clear();
        memset(v, 0, sizeof(v));
        Dfs(1, 0);
        sort(ans.begin(), ans.end());
        pr.Print(ans[0]);
        for (int i = 1; i < ans.size(); ++ i) {
            if (ans[i] == ans[i-1])
                continue;
            if ((ans[i] / 1000) != (ans[i-1] / 1000)) {
                pr.NewLine();
                pr.Print(ans[i]);
            }
            else
                pr.Print(ans[i]);
        }
        pr.NewLine();
    }

    return 0;
}