#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define W 10000

using namespace std;

class Number {
    private :
        int a[1024];

    public :
        Number () {}
        void set(int x) {
            int tx, d = 0;
            tx = x;
            memset(a,0,sizeof(a));
            while (tx > 0) {
                a[++ d] = (tx % 10);
                tx /= 10;
            }
        }
        void print() {
            int t = 1000;
            while ((a[t] == 0) && (t > 1)) t --;
            printf("%d",a[t]);
            for (int i = t - 1;i > 0;-- i) 
                printf("%04d",a[i]);
            printf("\n");
        }
        void multi(int x) {
            for (int i = 1;i <= 1000;++ i) 
                a[i] *= x;
            for (int i = 1;i <= 1000;++ i) {
                a[i + 1] += (a[i] / W);
                a[i] %= W; 
            }
        }
};

int gcd(int x,int y) {
    if ((x % y) == 0) return y;
    else return gcd(y,x % y);
}

int c[1024];
int n;
Number Ans;

int main() {

    while (scanf("%d",&n) == 1) {
        if (n == 0) break;
        for (int i = 1;i <= n;++ i) 
            c[i] = i + n;
        for (int i = 2;i <= (n + 1);++ i) {
            int tmp = i, tp;
            for (int j = 1;(j <= n) && (tmp != 1);++ j) {
                tp = gcd(tmp,c[j]);
                tmp /= tp;
                c[j] /= tp;
            }
        }
        Ans.set(1);
        for (int i = 1;i <= n;++ i) 
            if (c[i] != 1) Ans.multi(c[i]);
        for (int i = 1;i <= n;++ i) 
            Ans.multi(i);
        Ans.print();
    }
    
    return 0;
}
