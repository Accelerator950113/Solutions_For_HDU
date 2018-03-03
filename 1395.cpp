#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int n, x, t;

int main() {
    
    while (scanf("%d", &n) == 1) {
        if (n == 1 || n % 2 == 0)
            printf("2^? mod %d = 1\n", n);
        else {
            x = 1, t = 2;
            while (t != 1) {
                ++ x;
                t = (t * 2) % n;
            }
            printf("2^%d mod %d = 1\n", x, n);
        }
    }

    return 0;
}