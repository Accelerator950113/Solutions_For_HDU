#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct node {
    int id,t;
    node() {}
    node(int _i,int _t) {
        id = _i;
        t = _t;
    }
    friend bool operator <(const node &a1,const node &a2) {
        return (a1.t < a2.t);
    }
};

vector < node > A[8];
int score[512];
int n,x,hh,mm,ss,tn;
int ts;
char ch;

int gi() {
    ts = 0;
    ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch)) {
        ts = ts * 10 + (ch - '0');
        ch = getchar();
    }
    return ts;
}

int main() {

    while (scanf("%d",&n) == 1) {
        if (n < 1) break;
        for (int i = 0;i <= 5;++ i)
            A[i].clear();
        for (int i = 1;i <= n;++ i) {
            scanf("%d",&x);
            hh = gi();
            mm = gi();
            ss = gi();
            A[x].push_back(node(i,hh*3600 + mm*60 + ss));
        }
        for (int i = 1;i < 5;++ i) 
            sort(A[i].begin(),A[i].end());
        for (int i = 0;i < A[5].size();++ i)
            score[A[5][i].id] = 100;
        for (int i = 0;i < A[0].size();++ i)
            score[A[0][i].id] = 50;
        for (int i = 1;i < 5;++ i) {
            tn = A[i].size();
            for (int j = 1;j <= (tn / 2);++ j)
                score[A[i][j-1].id] = 55 + i*10;
            for (int j = (tn / 2) + 1;j <= tn;++ j)
                score[A[i][j-1].id] = 50 + i*10;
        }
        for (int i = 1;i <= n;++ i)
            printf("%d\n",score[i]);
        putchar('\n');
    }
    
    return 0;
}
