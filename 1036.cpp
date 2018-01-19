#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int ts;
char ch;

int gi() {
    ts = 0;
    ch = getchar();
    while ((!isdigit(ch)) && (ch != '-'))
        ch = getchar();
    if (ch == '-') {
        while (ch == '-')
            ch = getchar();
        return -1;
    }
    while (isdigit(ch)) {
        ts = ts * 10 + (ch - '0');
        ch = getchar();
    }
    return ts;
}

int main() {

    int n,num,hh,mm,ss,ans;
    double d,tot;
    bool flag;
    while (scanf("%d%lf",&n,&d) != EOF) {
        while (scanf("%d",&num) != EOF) {
            printf("%3d: ",num);
            tot = 0;
            flag = true;
            for (int i = 1;i <= n;++ i) {
                hh = gi();
                mm = gi();
                ss = gi();
                if (hh == -1) {
                    flag = false;
                }
                if (flag) {
                    tot += (3600*hh + 60*mm + ss);
                }
            }
            if (!flag) {
                puts("-");
                continue;
            }
            ans = (int)round(tot / d);
            printf("%d:%02d min/km\n",ans / 60,ans % 60);
        }
    }
    
    return 0;
}
