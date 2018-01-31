#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

string s1, s2;
size_t p;

int main() {

    while (cin >> s1 >> s2) {
        if (s2.size() > s1.size()) {
            printf("no\n");
            continue;
        }
        s1 = s1 + s1;
        p = s1.find(s2);
        if (p != string::npos) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}