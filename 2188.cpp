#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool f[16384];
int n, m;

int main() {

    scanf("%d", &n);
    while (scanf("%d%d", &n, &m) == 2) {
        f[n] = false;
        for (int i = n-1; i >= 0; -- i) {
            for (int j = 1; (j <= m) && (i+j <= n); ++ j)
                if (f[i+j] == false) {
                    f[i] = true;
                    break;
                }
                else f[i] = false;
        }
        printf("%s\n", f[0] ? ("Grass") : ("Rabbit"));
    }

    return 0;
}