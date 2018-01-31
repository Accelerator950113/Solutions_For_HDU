#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char S[262144], s[131072];
int f[262144];
int mx, id, ans;

int main() {

    while (scanf("%s", s) == 1) {
        n = strlen(s);
        S[n+n+2] = 0, S[0] = 2;
        for (int i = 0; s[i]; ++ i)
            S[i+i+1] = S[i+i+3] = 1, S[i+i+2] = s[i];
        mx = id = ans = 0;
        for (int i = 1; S[i]; ++ i) {
            if (mx > i)
                f[i] = min(f[id- (i-id)], mx-i);
            else
                f[i] = 1;
            while (S[i + f[i]] == S[i - f[i]])
                ++ f[i];
            if (f[i]+i > mx) {
                mx = f[i]+i;
                id = i;
            }
            ans = max(ans, f[i]-1);
        }
        printf("%d\n", ans);
    }

    return 0;
}