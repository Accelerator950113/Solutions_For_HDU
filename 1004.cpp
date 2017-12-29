#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

class word {
    private:
        char s[32];
    
    public:
        void clear() {
            memset(s,0,sizeof(s));
        }
        void read() {
            scanf("%s",s);
        }
        friend bool operator <(const word &a1,const word &a2) {
            for (int i = 0;i < 20;++ i) {
                if (a1.s[i] < a2.s[i]) return true;
                if (a1.s[i] > a2.s[i]) return false;
            }
            return false;
        }
        void print() {
            printf("%s\n",s);
        }
};

class solver {
    private:
        int n;
        word A[1024];
    
    public:
        bool init() {
            scanf("%d",&n);
            if (n == 0) return false;
            for (int i = 1;i <= n;++ i)
                A[i].clear();
            for (int i = 1;i <= n;++ i)
                A[i].read();
            return true;
        }
        void solve() {
            sort(A + 1,A + n + 1);
            int s = 1,bst = 1,pos = 1,cnt = 1;
            for (int i = 2;i <= n;++ i) {
                if (A[i - 1] < A[i]) {
                    s = i;
                    cnt = 1;
                }
                else {
                    cnt ++;
                    if (cnt > bst) {
                        bst = cnt;
                        pos = s;
                    }
                }
            }
            A[pos].print();
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
