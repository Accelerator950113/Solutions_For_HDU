#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int a, b;

int main() {
    
    while (scanf("%d%d", &a, &b) == 2) {
        if (a > b) 
            swap(a, b);
        double k = b-a;
        int sa = (int)(k * (1+sqrt(5))/2);
        if (sa == a) 
            printf("0\n");
        else 
            printf("1\n");
    }

    return 0;
}