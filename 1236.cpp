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

int n, m, g;
int a[32];
int tot, x;

struct node {
    char Name[32];
    int p;
    void readin() {
        scanf("%s%d", Name, &tot);
        p = 0;
        while (tot --) {
            scanf("%d", &x);
            p += a[x];
        }
    }
    void print() {
        printf("%s %d\n", Name, p);
    }
    friend bool operator <(const node &a1, const node &a2) {
        if (a1.p == a2.p) return (strcmp(a1.Name, a2.Name) < 0);
        else return (a1.p > a2.p);
    }
};

node stu[2048];

int main() {

    while (scanf("%d%d%d", &n, &m, &g) != EOF) {
        if (n == 0) break;
        for (int i = 1; i <= m; ++ i)
            scanf("%d", a + i);
        for (int i = 1; i <= n; ++ i)
            stu[i].readin();
        sort(stu+1, stu+n+1);
        int ans = 0;
        for (int i = 1; i <= n; ++ i)
            if (stu[i].p >= g) ans ++;
        printf("%d\n", ans);
        for (int i = 1; i <= ans; ++ i)
            stu[i].print();
    }

    return 0;
}