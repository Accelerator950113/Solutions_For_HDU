#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <sstream>

using namespace std;

string buf;
double s[16384];
int top, x, top2;
char s2[16384];
char ch;
double ans;

int main() {

    while (getline(cin, buf)) {
        if (buf == "0") break;
        stringstream ss;
        ss << buf;
        top = 1, top2 = 0;
        ss >> s[top];
        while (ss >> ch >> x) {
            if ((ch == '+') || (ch == '-')) {
                s2[++ top2] = ch;
                s[++ top] = x;
            }
            else {
                if (ch == '*') s[top] *= x;
                else s[top] /= x;
            }
        }
        ans = s[1];
        for (int i = 1; i <= top2; ++ i)
            if (s2[i] == '+') ans += s[i+1];
            else ans -= s[i+1];
        printf("%.2lf\n", ans);
    }

    return 0;
}