#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
    double x,y;
    point() {}
    void readin() {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator -(const point &a1,const point &a2) {
        point a3;
        a3.x = a1.x - a2.x;
        a3.y = a1.y - a2.y;
        return a3;
    }
    friend double operator *(const point &a1,const point &a2) {
        return (a1.x * a2.y - a2.x * a1.y);
    }
} A[131072],B[131072];

int n;
bool ok;
int lst[2048],l;
double t1,t2;

bool cross(int a,int b) {
    t1 = (B[a] - A[a]) * (A[b] - A[a]);
    t2 = (B[a] - A[a]) * (B[b] - A[a]);
    if (t1 * t2 > 0) return false;
    t1 = (B[b] - A[b]) * (A[a] - A[b]);
    t2 = (B[b] - A[b]) * (B[a] - A[b]);
    if (t1 * t2 > 0) return false;
    return true; 
}

int main() {

    while (scanf("%d",&n) == 1) {
        if (n == 0) break;
        for (int i = 1;i <= n;++ i) {
            A[i].readin();
            B[i].readin();
        }
        l = 0;
        for (int i = 1;i <= n;++ i) {
            ok = true;
            for (int j = i + 1;j <= n;++ j) 
                if (cross(i,j)) {
                    ok = false;
                    break;
                }
            if (ok) lst[++ l] = i;
        }
        printf("Top sticks: ");
        for (int i = 1;i < l;++ i) 
            printf("%d, ",lst[i]);
        printf("%d.\n",lst[l]);
    }
    
    return 0;
}
