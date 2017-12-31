#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[524288],x,r;
int n;
int cst = 0;
int ans[524288],len;

int find(int n,int m) {
    int l = 1,r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (m >= ans[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main() {

    while (scanf("%d",&n) != EOF) {
        memset(A,0,sizeof(A));
        for (int i = 1;i <= n;++ i) {
            scanf("%d%d",&x,&r);
            A[x] = r;
        }
        len = 1, ans[1] = A[1];
        for (int i = 2;i <= n;++ i) {
            int t = find(len,A[i]);
            ans[t] = A[i];
            if (t > len) len ++;
        }
        printf("Case %d:\n",++ cst);
        if (len == 1) printf("My king, at most 1 road can be built.\n\n");
        else printf("My king, at most %d roads can be built.\n\n",len);
    }
    
    return 0;
}
