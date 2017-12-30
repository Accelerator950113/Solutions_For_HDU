#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

double sum = 2.5;
int jc = 2;

int main() {

    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for (int i = 3;i < 10;++ i) {
        jc = jc * i;
        sum = sum + (1.0 / (double)jc);
        printf("%d %.9lf\n",i,sum);
    }
    
    return 0;
}
