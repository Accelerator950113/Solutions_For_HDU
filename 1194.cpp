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
    
    scanf("%d", &a);
    while (scanf("%d%d", &a, &b) == 2) {
        if (b > a)
            printf("impossible\n");
        else if ((a-b) & 1)
            printf("impossible\n");
        else 
            printf("%d %d\n", (a-b)/2 + b, (a-b)/2);
    }

    return 0;
}