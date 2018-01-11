#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char s[2048];

int main() {

    while (gets(s)) {
        int l = strlen(s);
        for (int i = 0;i < l;++ i)
            if ((s[i] >= 'A') && (s[i] <= 'Z')) s[i] += ('a' - 'A');
        puts(s);
    }
    
    return 0;
}
