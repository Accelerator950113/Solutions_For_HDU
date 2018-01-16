#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define LL long long
#define END 87654321ll

using namespace std;

struct node {
    LL key,pre;
    node() {}
    node(LL _k,LL _p) {
        key = _k;
        pre = _p;
    }
};

struct node2 {
    LL key,nxt;
    node2() {}
    node2(LL _k,LL _n) {
        key = _k;
        nxt = _n;
    }
};

vector < node2 > H2[30031];
vector < node > H[30031];
queue < LL > Q,Q2;
queue < int > Q1,Q3;
vector < int > g[16];
int a[16],b[16];
int lst[16];
LL c[16];
int addr;

void clean() {
    for (int i = 0;i < 30031;++ i) {
        H[i].clear();
        H2[i].clear();
    }
    while (!Q.empty()) 
        Q.pop();
    while (!Q1.empty())
        Q1.pop();
    while (!Q2.empty())
        Q2.pop();
    while (!Q3.empty())
        Q3.pop();
}

void insert(LL x,LL y) {
    addr = (int)(x % 30031);
    H[addr].push_back(node(x,y));
}

void insert2(LL x,LL y) {
    addr = (int)(x % 30031);
    H2[addr].push_back(node2(x,y));
}

LL getpre(LL x) {
    addr = (int)(x % 30031);
    for (int i = 0;i < H[addr].size();++ i)
        if (H[addr][i].key == x) return H[addr][i].pre;
    return -1;
}

LL getnxt(LL x) {
    addr = (int)(x % 30031);
    for (int i = 0;i < H2[addr].size();++ i)
        if (H2[addr][i].key == x) return H2[addr][i].nxt;
    return -1;
}

int gi() {
    char ch = getchar();
    while ((!isdigit(ch)) && (ch != 'x') && (ch != EOF))
        ch = getchar();
    if (ch == EOF) return -1;
    if (isdigit(ch)) return (ch - '0');
    return 0;
}

LL get(LL state,int pos) {
    return ((state % c[pos + 1]) / c[pos]);
}

void output(LL x) {
    LL y = getpre(x);
    if (y == -3) return;
    output(y);
    int t1 = 1;
    while (((x % c[t1+1]) / c[t1]) != 0) 
        t1 ++;
    int t = 1;
    while (((y % c[t+1]) / c[t]) != 0) 
        t ++;
    t -= t1;
    if (t == 3) putchar('u');
    else if (t == -3) putchar('d');
    else if (t == -1) putchar('r');
    else if (t == 1) putchar('l');
}

void output2(LL x) {
    LL y = getnxt(x);
    if (y == -3) return;
    int t1 = 1;
    while (((x % c[t1+1]) / c[t1]) != 0) 
        t1 ++;
    int t = 1;
    while (((y % c[t+1]) / c[t]) != 0) 
        t ++;
    t = t1 - t;
    if (t == 3) putchar('u');
    else if (t == -3) putchar('d');
    else if (t == -1) putchar('r');
    else if (t == 1) putchar('l');
    output2(y);
}

int main() {

    for (int i = 1;i <= 9;++ i)
        g[i].clear();
    g[1].push_back(2), g[1].push_back(4);
    g[2].push_back(1), g[2].push_back(3), g[2].push_back(5);
    g[3].push_back(2), g[3].push_back(6);
    g[4].push_back(1), g[4].push_back(5), g[4].push_back(7);
    g[5].push_back(2), g[5].push_back(4), g[5].push_back(6), g[5].push_back(8);
    g[6].push_back(3), g[6].push_back(5), g[6].push_back(9);
    g[7].push_back(4), g[7].push_back(8);
    g[8].push_back(5), g[8].push_back(7), g[8].push_back(9);
    g[9].push_back(6), g[9].push_back(8);
    c[1] = 1ll;
    for (int i = 2;i <= 10;++ i)
        c[i] = c[i - 1] * 10ll;

    while (true) {

        a[1] = gi();
        if (a[1] == -1) break;
        for (int i = 2;i < 10;++ i)
            a[i] = gi();

        lst[0] = 0;
        for (int i = 1;i < 10;++ i)
            if (a[i] != 0) lst[++ lst[0]] = a[i];
        int tc = 0;
        for (int i = 2;i <= lst[0];++ i)
            for (int j = 1;j < i;++ j)
                if (lst[j] > lst[i]) tc ++;
        if (tc & 1) {
            puts("unsolvable");
            continue;
        }

        clean();

        LL tp = 0ll;
        for (int i = 1;i < 10;++ i)
            tp += (a[i] * c[i]);
        Q.push(tp);
        insert(tp,-3);
        int xx = 1;
        while (a[xx] != 0) 
            xx ++;
        Q1.push(xx);
        insert2(END,-3);
        Q2.push(END);
        Q3.push(9);
        LL cnt,mid;
        bool flag = false;
        int ccc = 0;
        while ((!Q.empty()) && (!Q2.empty()) && (!flag)) {

            tp = Q.front();
            xx = Q1.front();
            Q.pop();
            Q1.pop();
            for (int i = 0;i < g[xx].size();++ i) {
                cnt = tp + get(tp,g[xx][i]) * (c[xx] - c[g[xx][i]]);
                if (getpre(cnt) == -1) {
                    insert(cnt,tp);
                    Q.push(cnt);
                    Q1.push(g[xx][i]);
                }
                if (getnxt(cnt) != -1) {
                    flag = true;
                    mid = cnt;
                    break;
                }
            }
            if (flag) break;

            tp = Q2.front();
            xx = Q3.front();
            Q2.pop();
            Q3.pop();
            for (int i = 0;i < g[xx].size();++ i) {
                cnt = tp + get(tp,g[xx][i]) * (c[xx] - c[g[xx][i]]);
                if (getnxt(cnt) == -1) {
                    insert2(cnt,tp);
                    Q2.push(cnt);
                    Q3.push(g[xx][i]);
                }
                if (getpre(cnt) != -1) {
                    flag = true;
                    mid = cnt;
                    break;
                }
            }
            if (flag) break;

        }
        output(mid);
        output2(mid);
        putchar('\n');
    }

    return 0;
}
