#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#define pi 3.1415927

using namespace std;

double r,t,dist,MPH;
int c,cst = 0;

int main() {

    while (cin >> r >> c >> t) {
        if (c == 0) break;
        dist = (pi*r*c) / (12*5280);
        MPH = (dist*3600) / t;
        printf("Trip #%d: %.2lf %.2lf\n",++ cst,dist,MPH);
    }
    
    return 0;
}
