#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

struct room {
    int j,f;
    void readin() {
        scanf("%d%d",&j,&f);
    }
    friend bool operator <(const room &a1,const room &a2) {
        return ((a1.j * a2.f) < (a2.j * a1.f));
    }
    double getpart(double x) {
        return ((x * j) / f);
    }
} A[1024];

int n,m;
double remain,tot;

int main() {

    while(scanf("%d%d",&m,&n) == 2) {
        if ((n == -1) && (m == -1)) break;
        tot = 0, remain = m;
        for (int i = 1;i <= n;++ i) A[i].readin();
        sort(A + 1,A + n + 1);
        for (int i = n;i > 0;-- i) {
            if (remain > A[i].f) {
                remain -= A[i].f;
                tot += A[i].j;
            }
            else {
                tot += A[i].getpart(remain);
                break;
            }
        }
        printf("%.3lf\n",tot);
    }
    
    
    return 0;
}
