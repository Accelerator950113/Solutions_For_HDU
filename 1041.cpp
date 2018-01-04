#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Number {
    int a[256];
    Number () {}
    void clean() {
        memset(a,0,sizeof(a));
    }
    void set() {
        a[1] = 1;
    }
    friend Number operator +(const Number &a1,const Number &a2) {
        Number a3;
        a3.clean();
        for (int i = 1;i <= 200;++ i) 
            a3.a[i] = a1.a[i] + a2.a[i];
        for (int i = 1;i <= 200;++ i) {
            a3.a[i + 1] += (a3.a[i] / 10000);
            a3.a[i] %= 10000;
        }
        return a3;
    }
    void multi(int x) {
        for (int i = 1;i <= 200;++ i) 
            a[i] *= x;
        for (int i = 1;i <= 200;++ i) {
            a[i + 1] += (a[i] / 10000);
            a[i] %= 10000;
        }
    }
    void print() {
        int t = 200;
        while ((a[t] == 0) && (t > 1))
            t --;
        printf("%d",a[t --]);
        for (;t > 0;-- t)
            printf("%04d",a[t]);
        printf("\n");
    }
};

Number F00,F01,F1,TMP;
Number Ans[1024];
int n;

int main() {

    F00.clean();
    F01.clean();
    F1.clean();
    F1.set();
    F01.set();
    Ans[1].clean();
    for (int i = 1;i <= 1000;++ i) {
        TMP = F01;
        F01 = F00 + F1;
        F00 = TMP;
        F1.multi(2);
        Ans[i + 1] = F00;
    }

    while (cin >> n) 
        Ans[n].print();
    
    return 0;
}
