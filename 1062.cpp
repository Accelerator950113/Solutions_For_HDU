#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char s[1024],ch;
int top;
int n;

int main() {

    scanf("%d",&n);
    ch = getchar();
    while (n --) {
        top = 0;
        while (true) {
            ch = getchar();
            if ((ch == ' ') || (ch == '\n')) {
                while (top)
                    putchar(s[top --]);
                putchar(ch);
            }
            else s[++ top] = ch;
            if (ch == '\n') break;
        }
    }
    
    return 0;
}
