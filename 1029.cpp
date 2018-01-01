#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,x,c,cx;

int main() {

    while (scanf("%d",&n) == 1) {
        c = 0;
        for (int i = 1;i <= n;++ i) {
            scanf("%d",&x);
            if (c == 0) {
                c = 1;
                cx = x;
            }
            else {
                if (x == cx) c ++;
                else c --;
            }
        }
        printf("%d\n",cx);
    }
    
    return 0;
}
