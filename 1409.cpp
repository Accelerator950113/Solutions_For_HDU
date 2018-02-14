#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct node {
    int p[8];
    void clear() {
        memset(p, 0xff, sizeof(p));
    }
};

node T[16];
string buf;

int Trans(char x) {
    if (isdigit(x))
        return 1;
    if (x == '.')
        return 2;
    if (x == 'E')
        return 3;
    if (x == '-')
        return 4;
    return 5;
}

void Add(int x, int y, int t) {
    T[x].p[t] = y;
}

void BuildChecker() {
    for (int i = 1; i <= 7; ++ i)
        T[i].clear();
    Add(1, 2, 1);
    Add(2, 2, 1);
    Add(2, 3, 2);
    Add(2, 5, 3);
    Add(3, 4, 1);
    Add(4, 4, 1);
    Add(4, 5, 3);
    Add(5, 6, 4);
    Add(6, 7, 1);
    Add(5, 7, 1);
    Add(7, 7, 1);
}

bool Go(int i, int id) {
    if (id == -1)
        return false;
    if (i == buf.size())
        return (id == 2 || id == 4 || id == 7);
    return Go(i+1, T[id].p[Trans(buf[i])]);
}

int main() {
    
    BuildChecker();

    getline(cin, buf);
    while (getline(cin, buf)) 
        cout << ((Go(0, 1)) ? ("YES") : ("NO")) << endl;

    return 0;
}