#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

class number {
    private:
        int a[2048];
    
    public:
        void getnum(char *c,int f,int r) {
            memset(a,0,sizeof(a));
            for (int i = r,j = 1;i >= f;-- i,++ j)
                a[j] = c[i] - '0';
        }
        friend number operator +(const number &a1,const number &a2) {
            number a3;
            memset(a3.a,0,sizeof(a3.a));
            for (int i = 0;i <= 2000;++ i)
                a3.a[i] = a1.a[i] + a2.a[i];
            for (int i = 0;i <= 2000;++ i) {
                a3.a[i + 1] += a3.a[i] / 10;
                a3.a[i] %= 10;
            }
            return a3;
        }
        void printnum() {
            int r = 2002;
            while (a[r] == 0) r --;
            for (int i = r;i > 0;-- i) printf("%d",a[i]);
        }
} A,B,C;

int tot;
char s[4096];

int main() {
    
    gets(s);
    sscanf(s,"%d",&tot);
    
    for (int c = 1;c <= tot;++ c) {
        if (c > 1) printf("\n");
        gets(s);
        int md = 0,ed = strlen(s) - 1;
        while (s[md] != ' ') md ++;
        A.getnum(s,0,md - 1);
        B.getnum(s,md + 1,ed);
        C = A + B;
        printf("Case %d:\n",c);
        A.printnum();
        printf(" + ");
        B.printnum();
        printf(" = ");
        C.printnum();
        printf("\n");
    }
    
    return 0;
}
