#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[1048576];
int x,y;
int t;

int find(long long x) {
    if (x <= 1000000ll) {
        if (ans[x] != 0) return ans[x]; 
        if ((x & 1) == 0) ans[x] = (find(x / 2) + 1);
        else ans[x] = (find(((x / 2) * 3) + 2) + 2);
        return ans[x];
    }
    else {
        if ((x & 1) == 0) return (find(x / 2) + 1);
        else return (find(((x / 2) * 3) + 2) + 2);
    }
}

int main() {

    memset(ans,0,sizeof(ans));
    ans[1] = 1;
    for (int i = 2;i <= 1000000;++ i)
        if (ans[i] == 0) ans[i] = find((long long)i);

    while (scanf("%d%d",&x,&y) == 2) {
        t = 0;
        if (x > y) {
            for (int i = y;i <= x;++ i)
                if (ans[i] > t) t = ans[i];
        }
        else {
            for (int i = x;i <= y;++ i) 
                if (ans[i] > t) t = ans[i];
        }
        printf("%d %d %d\n",x,y,t);
    }
    
    return 0;
}
