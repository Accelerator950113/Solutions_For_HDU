#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char s[1024];
int y,m,d;
int T;

bool run(int x) {
    if (x % 400 == 0) return true;
    return ((x % 4 == 0) && (x % 100 != 0));
}

int main() {

    gets(s);
    sscanf(s,"%d",&T);
    while (T --) {
        gets(s);
        y = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
        m = (s[5]-'0')*10 + (s[6]-'0');
        d = (s[8]-'0')*10 + (s[9]-'0');
        if (run(y) && (m == 2) && (d == 29)) {
            puts("-1");
            continue;
        }
        int ans = 0;
        for (int i = 1;i <= 18;++ i) 
            if (run(y+i)) ans += 366;
            else ans += 365;
        if ((run(y)) && (m <= 2)) ans ++;
        if ((run(y + 18)) && (m <= 2)) ans --;
        cout << ans << endl;
    }

    return 0;
}