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

int T, n;

struct node {
    char Name[32];
    char t1[16], t2[16];
    void readin() {
        scanf("%s%s%s", Name, t1, t2);
    }
};

node stu[131072];

bool cmp1(const node &a1, const node &a2) {
    return (strcmp(a1.t1, a2.t1) < 0);
}

bool cmp2(const node &a1, const node &a2) {
    return (strcmp(a1.t2, a2.t2) > 0);
}

int main() {

    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i)
            stu[i].readin();
        sort(stu, stu+n, cmp1);
        printf("%s ", stu[0].Name);
        sort(stu, stu+n, cmp2);
        printf("%s\n", stu[0].Name);
    }

    return 0;
}