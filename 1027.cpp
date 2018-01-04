#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int jc[10];
int n,m,cnt;
int pre[1024],nxt[1024];

void del(int x) {
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];
}

void dy(int pos,int x) {
    if (pos == 1) printf("%d",x);
    else printf(" %d",x);
}

int main() {

    jc[0] = 1;
    for (int i = 1;i <= 8;++ i) 
        jc[i] = jc[i - 1] * i;

    while (cin >> n >> m) {
        m --;
        nxt[0] = 1, pre[n + 1] = n;
        for (int i = 1;i <= n;++ i)
            pre[i] = i - 1, nxt[i] = i + 1;
        for (int i = 1;i <= n;++ i) {
            cnt = nxt[0];
            if ((n - i + 1) <= 8) {
                while (m >= jc[n - i]) {
                    m -= jc[n - i];
                    cnt = nxt[cnt];
                }
                dy(i,cnt);
                del(cnt);
            }
            else {
                dy(i,cnt);
                del(cnt);
            }
        }
        printf("\n");
    }
    
    return 0;
}
