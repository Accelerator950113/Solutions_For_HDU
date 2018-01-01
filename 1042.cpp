#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Number {
    int a[9200];
    Number() {}
    void clean() {
        memset(a,0,sizeof(a));
    }
    void set(int x) {
        int l = 0, t = x;
        while (t > 0) {
            a[++ l] = t % 10;
            t /= 10;
        }
    }
    void multi(int x) {
        for (int i = 1;i <= 9000;++ i) 
            a[i] *= x;
        for (int i = 1;i <= 9000;++ i) {
            a[i + 1] += (a[i] / 10000);
            a[i] %= 10000;
        }
    }
    void print() {
        int t = 9000;
        while ((a[t] == 0) && (t > 1)) t --;
        printf("%d",a[t]);
        t --;
        for (int i = t;i > 0;-- i) printf("%04d",a[i]);
        printf("\n");
    }
};

Number A;
int n;

int main() {

    while (scanf("%d",&n) == 1) {
        A.clean();
        A.set(1);
        for (int i = 1;i <= n;++ i) 
            A.multi(i);
        A.print();
    }
    
    return 0;
}
