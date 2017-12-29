#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define eps 1e-6
#define INF 1e50

using namespace std;

double getabs(double x) {
    if (x < 0) return -x;
    else return x;
}

double pf(double x) {
    return x * x;
}

bool isequal(double x,double y) {
    return (getabs(x - y) < eps);
}

struct point {
    double x,y;
    void readin() {
        scanf("%lf%lf",&x,&y);
    }
    friend bool operator <(const point &a1,const point &a2) {
        if (isequal(a1.x,a2.x)) return (a1.y < a2.y);
        else return (a1.x < a2.x);
    }
} A[131072];

bool cmp(int x,int y) {
    return (A[x].y < A[y].y);
}

double dis(int a,int b) {
    return sqrt(pf(A[a].x - A[b].x) + pf(A[a].y - A[b].y));
}

int n,B[131072];
double ans;

double solve(int left,int right) {
    if (left == right) return INF;
    if ((left + 1) == right) return dis(left,right);
    int mid = (left + right) / 2;
    double d = solve(left,mid);
    double d2 = solve(mid + 1,right);
    int i;
    if (d2 < d) d = d2;
    B[0] = 0;
    for (i = left;i <= right;++ i) 
        if (getabs(A[i].x - A[mid].x) < d) {
            B[0] ++;
            B[B[0]] = i;
        }  
    sort(B + 1,B + B[0] + 1,cmp);
    for (i = 1;i <= B[0];++ i) 
        for (int j = i + 1;(j <= B[0]) && (getabs(A[B[j]].y - A[B[i]].y) < d);++ j) 
            if (dis(B[i],B[j]) < d) d = dis(B[i],B[j]);
    return d;
}

int main() {

    while(scanf("%d",&n) == 1) {
        if (n == 0) break;
        for (int i = 1;i <= n;++ i) A[i].readin();
        sort(A + 1,A + n + 1);
        ans = solve(1,n) / 2.0;
        printf("%.2lf\n",ans);
    }
    
    
    return 0;
}
