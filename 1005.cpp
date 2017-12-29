#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MOD 7

using namespace std;

class matrix {
    private:
        int r,c;
        int a[4][4];
    
    public:
        void setSize(int rr,int cc) {
            r = rr;
            c = cc;
        }
        void setNum(int ii,int jj,int t) {
            a[ii][jj] = t;
        }
        friend matrix operator *(const matrix &a1,const matrix &a2) {
            matrix c1;
            c1.r = a1.r;
            c1.c = a2.c;
            for (int i = 1;i <= c1.r;++ i)
                for (int j = 1;j <= c1.c;++ j) {
                    int tmp = 0;
                    for (int k = 1;k <= a1.c;++ k)
                        tmp = (tmp + a1.a[i][k] * a2.a[k][j]) % MOD;
                    c1.a[i][j] = tmp;
                }
            return c1;
        }
        matrix f(int n) {
            if (n == 1) return (*this);
            matrix tp = f(n / 2);
            tp = tp * tp;
            if ((n % 2) == 1) tp = tp * (*this);
            return tp;
        }
        void getAnswer() {
            printf("%d\n",a[1][2]);
        }
};

class solver {
    private:
        int A,B,n;
        matrix S0,G,S1;
    
    public:
        bool init() {
            scanf("%d%d%d",&A,&B,&n);
            if ((A == 0) && (B == 0) && (n == 0)) return false;
            return true;
        }
        void solve() {
            if (n <= 2) {
                printf("1\n");
                return;
            }
            S0.setSize(1,2);
            S0.setNum(1,1,1),S0.setNum(1,2,1);
            G.setSize(2,2);
            G.setNum(1,1,0),G.setNum(1,2,B % MOD);
            G.setNum(2,1,1),G.setNum(2,2,A % MOD);
            
            G = G.f(n - 2);
            S1 = S0 * G;
            
            S1.getAnswer();
        }
};

class master {
    private:
        solver S;
    
    public:
        void work() {
            while (S.init()) {
                S.solve();
            }
        }
} M;

int main() {
    
    M.work();
    
    return 0;
}
