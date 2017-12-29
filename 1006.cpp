#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ps (1.0 / 120.0)
#define pf 0.1
#define pm 6.0

using namespace std;

struct yz {
    double x;
    int d;

    friend bool operator <(const yz &a1,const yz &a2) {
        return (a1.x < a2.x);
    }
};

struct xl {
    yz X[256];
    int len;
    void init() {
        len = 0;
    }
    void pb(double xx,double dd) {
        len ++;
        X[len].x = xx;
        X[len].d = dd;
    }
} F;

double C,C2,ans,total;
double A,B;
double x1,x2;

double calc(double x,double y) {
    if (x > 60) return 60;
    if (y < 0) return 60;
    if (x < 0) {
        if (y < 60) return (60 - y);
        else return 0;
    }
    if (y > 60) {
        if (x > 0) return x;
        else return 0; 
    }
    return (x + 60 - y);
}

void cl(double x,double y) {
    if (x > 60) {
        F.pb(0,1);
        F.pb(60,-1);
        return;
    }
    if (y < 0) {
        F.pb(0,1);
        F.pb(60,-1);
        return;
    }
    if (x < 0) {
        if (y < 60) F.pb(y,1),F.pb(60,-1);
        return;
    }
    if (y > 60) {
        if (x > 0) F.pb(0,1),F.pb(x,-1);
        return;
    }
    F.pb(0,1);
    F.pb(x,-1);
    F.pb(y,1);
    F.pb(60,-1);
}

void cl2(double x,double y) {
    if ((y < 0) || (x > 60)) return;
    if (x < 0) {
        F.pb(0,1);
        if (y > 60) F.pb(60,-1);
        else F.pb(y,-1);
        return;
    }
    if (y > 60) {
        F.pb(60,-1);
        if (x < 0) F.pb(0,1);
        else F.pb(x,1);
        return;
    }
    F.pb(x,1);
    F.pb(y,-1);
}

double calc() {
    double s = 0;
    int dd = 0;
    for (int i = 1;i < F.len;++ i) {
        dd += F.X[i].d;
        if (dd == 6) s += (F.X[i + 1].x - F.X[i].x);
    }
    return s;
}

int main() {

    while(scanf("%lf",&C) == 1) {
        if (C < -0.1) break;
        C2 = 360 - C;
        ans = 0, total = 360 * 60;
        for (int i = 0;i < 360;++ i) {
            F.init();
            A = 0.5 * i;
            B = 6.0 * (i % 60);
            x1 = (A - B - C) / (pf - ps), x2 = (A - B + C) / (pf - ps);
            cl(x1,x2);
            x1 = (A - C) / (pm - ps), x2 = (A + C) / (pm - ps);
            cl(x1,x2);
            x1 = (B - C) / (pm - pf), x2 = (B + C) / (pm - pf);
            cl(x1,x2);
            x1 = (A - B - C2) / (pf - ps), x2 = (A - B + C2) / (pf - ps);
            cl2(x1,x2);
            x1 = (A - C2) / (pm - ps), x2 = (A + C2) / (pm - ps);
            cl2(x1,x2);
            x1 = (B - C2) / (pm - pf), x2 = (B + C2) / (pm - pf);
            cl2(x1,x2);
            F.pb(60,0);
            sort(F.X + 1,F.X + F.len + 1);
            ans += calc();
        }
        ans *= 100.0;
        printf("%.3lf\n",ans / total);
    }
    
    
    return 0;
}
