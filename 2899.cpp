#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#define eps 1e-9

using namespace std;

double Y;
double l, r, mid;

double F(double x, double y) {
    return (6.0*pow(x, 7.0) + 8.0*pow(x, 6.0) + 7.0*pow(x, 3.0) + 5*x*x - y*x);
}

double f(double x) {
    return (42.0*pow(x, 6.0) + 48.0*pow(x, 5.0) + 21.0*x*x + 10*x);
}

int main() {

    cin >> Y;
    while (cin >> Y) {
        if (Y > f(100+eps)) {
            printf("%.4lf\n", F(100, Y));
            continue;
        }
        l = 0, r = 100;
        while (r-l > eps) {
            mid = (l+r) / 2;
            if (f(mid) > Y) r = mid - eps;
            else l = mid;
        }
        printf("%.4lf\n", F(l, Y));
    }

    return 0;
}