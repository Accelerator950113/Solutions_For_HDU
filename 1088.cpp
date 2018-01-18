#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

char str[128];
int l;
int cnt;

int main() {

    cnt = 0;
    while (scanf("%s",str) != EOF) {
        if (strcmp(str,"<br>") == 0) {
            putchar('\n');
            cnt = 0;
            continue;
        }
        if (strcmp(str,"<hr>") == 0) {
            if (cnt != 0) putchar('\n');
            for (int i = 0;i < 80;++ i)
                putchar('-');
            putchar('\n');
            cnt = 0;
            continue;
        }
        l = strlen(str);
        if (cnt == 0) {
            cnt += l;
            printf("%s",str);
            continue;
        }
        if ((cnt + 1 + l) <= 80) {
            printf(" %s",str);
            cnt += (1 + l);
        }
        else {
            putchar('\n');
            cnt = l;
            printf("%s",str);
        }
    }
    putchar('\n');
    
    return 0;
}
