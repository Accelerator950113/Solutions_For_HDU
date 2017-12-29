#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

class sequence {
    private:
        int n;
        int a[131072];
    
    public:
        void clear() {
            n = 0;
        }
        void add(int x) {
            n ++;
            a[n] = x;
        }
        void getmax() {
            int m = a[1],ms = 1,mt = 1,cnt = 0,ps = 1;
            for (int i = 1;i <= n;++ i) {
                cnt += a[i];
                if (cnt < 0) {
                    cnt = 0;
                    ps = i + 1;
                }
                else {
                    if (cnt > m) {
                        m = cnt;
                        ms = ps;
                        mt = i;
                    }
                }
            }
            if (m < 0) {
                for (int i = 2;i <= n;++ i) {
                    if (a[i] > m) {
                        ms = i;
                        mt = i;
                        m = a[i];
                    }
                }
            }
            printf("%d %d %d\n",m,ms,mt);
        }
};

class solver {
    private:
        int n,x;
        sequence A;
    
    public:
        void init() {
            A.clear();
            scanf("%d",&n);
            for (int i = 1;i <= n;++ i) {
                scanf("%d",&x);
                A.add(x);
            }
        }
        void solve(int c) {
            if (c > 1) printf("\n");
            printf("Case %d:\n",c);
            A.getmax();
        }
};

class master {
    private:
        int totalCase;
        solver S;
    
    public:
        void init() {
            scanf("%d",&totalCase);
        }
        void work() {
            for (int i = 1;i <= totalCase;++ i) {
                S.init();
                S.solve(i);
            }
        }
} M;

int main() {
    
    M.init();
    M.work();
    
    return 0;
}
