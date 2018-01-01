#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int cf[2] = {6,4};
const int r[10] = {1,1,2,6,4,2,2,4,2,8};

struct Number {
    int a[1024];
    Number() {}
    void clean() {
        memset(a,0,sizeof(a));
    }
    void get(char* c) {
        int l = strlen(c) - 1, t = 0;
        while (l >= 0) 
            a[++ t] = c[l --] - '0';
    }
    void div(int x) {
        int rest = 0;
        for (int i = 1000;i > 0;-- i) {
            rest = rest * 10 + a[i];
            a[i] = rest / x;
            rest %= x;
        }
    }
    bool zero() {
        for (int i = 2;i <= 1000;++ i)
            if (a[i] != 0) return false;
        return true;
    }
    void print() {
        int t = 1000;
        while ((a[t] == 0) && (t > 1)) t --;
        for (int i = t;i > 0;-- i) printf("%d",a[i]);
        printf("\n");
    }
};

char s[1024];
Number A;
int ans;

int main() {

    while (gets(s)) {
        A.clean();
        A.get(s);
        ans = 1;
        while (true) {
            ans = (ans * r[A.a[1]]) % 10;
            if (A.zero()) break;
            ans = (ans * cf[A.a[2] % 2]) % 10;
            A.div(5);
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
