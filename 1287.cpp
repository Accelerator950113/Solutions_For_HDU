#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n;
int a[1048576];

int main() {

    while (scanf("%d",&n) == 1) {
        for (int i = 0;i < n;++ i)
            scanf("%d",&a[i]);
        for (int i = (int)'A';i <= (int)'Z';++ i) {
            bool ok = true;
            for (int j = 0;j < n;++ j)
                if (((a[j]^i) < (int)'A') || ((a[j]^i) > (int)'Z')) {
                    ok = false;
                    break;
                }
            if (ok) {
                for (int j = 0;j < n;++ j)
                    putchar(a[j]^i);
                putchar('\n');
            }
        }
    }

    return 0;
}