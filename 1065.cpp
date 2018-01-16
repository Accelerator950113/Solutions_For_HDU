#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    int t;
    double x, y;
    cin >> t;
    for(int i = 1;i <= t;++ i) {
        cin >> x >> y;
        printf("Property %d: This property will begin eroding in year %d.\n",
            i, int((x*x + y*y) * 3.1415926 / 100 + 1));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}