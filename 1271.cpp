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

int n, a, b, c;
vector < int > ans;

int main() {
    
    while (scanf("%d", &n) == 1 && n > 0) {
        ans.clear();
        for (int i = 1; i <= n; i *= 10) {
            c = (n / i) / 11;
            b = (n / i) % 11;
            if (b+c > 0 && b < 10) {
                a = (n - b*i - 11*c*i) / 2;
                if (n == 2*a + b*i + 11*c*i)
                    ans.push_back(a + b*i + 10*c*i);
            }
            b --;
            if (b+c > 0 && b >= 0 && b < 10) {
                a = (n - b*i - 11*c*i) / 2;
                if (n == 2*a + b*i + 11*c*i)
                    ans.push_back(a + b*i + 10*c*i);
            }
        }
        if (ans.size() == 0) 
            printf("No solution.\n");
        else {
            sort(ans.begin(), ans.end());
            printf("%d", ans[0]);
            for (int i = 1; i < ans.size(); ++ i)
                if (ans[i] != ans[i-1])
                    printf(" %d", ans[i]);
            printf("\n");
        }
    }

    return 0;
}