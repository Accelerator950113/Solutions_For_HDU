#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct node {
    int id;
    double key;
    node() {}
    friend bool operator <(const node &a1,const node &a2) {
        if (a1.key == a2.key) return (a1.id < a2.id);
        return (a1.key > a2.key);
    }
};

int n,m,k;
double x;
node A[1048576];
int lst[1048576];

int main() {

    while (scanf("%d%d%d",&n,&m,&k) == 3) {
        for (int i = 1;i <= m;++ i) {
            A[i].id = i;
            A[i].key = 0;
        }
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= m;++ j) {
                scanf("%lf",&x);
                A[j].key += x;
            }
        sort(A + 1,A + m + 1);
        for (int i = 1;i <= k;++ i)
            lst[i] = A[i].id;
        sort(lst + 1,lst + k + 1);
        for (int i = k;i > 1;-- i)
            printf("%d ",lst[i]);
        printf("%d\n",lst[1]);
    }

    return 0;
}