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
#define INF 2147483644

using namespace std;

char ch;
string buf;
int len, sum;

int main() {
    
    while (cin >> ch >> buf) {
        len = buf.size();
        sum = 0;
        if ('A' <= ch && ch <= 'Z')
            ch += ('a' - 'A');
        for (int i = 0; i < buf.size(); ++ i)
            if ('A' <= buf[i] && buf[i] <= 'Z')
                buf[i] += ('a' - 'A');
        for (int i = 0; i < buf.size(); ++ i)
            if (buf[i] == ch)
                ++ sum;
        printf("%.5lf\n", (double)sum / (double)len);
    }

    return 0;
}