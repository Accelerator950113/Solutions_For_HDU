#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int tj;
char pre,cnt;

int main() {

	scanf("%d",&N);
    while (N --) {
        pre = '#';
        tj = 0;
        cnt = getchar();
        while ((cnt < 'A') || (cnt > 'Z')) cnt = getchar();
        while (('A' <= cnt) && (cnt <= 'Z')) {
            if (cnt != pre) {
                if (tj > 0) {
                    if (tj == 1) putchar(pre);
                    else printf("%d%c",tj,pre);
                }
                pre = cnt;
                tj = 1;
            }
            else tj ++;
            pre = cnt;
            cnt = getchar();
        }
        if (tj == 1) putchar(pre);
        else printf("%d%c",tj,pre);
        putchar('\n');
    }
    
    return 0;
}
