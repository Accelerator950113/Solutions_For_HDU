#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char p1[4] = "st";
char p2[4] = "nd";
char p3[4] = "rd";
char p4[4] = "th";
priority_queue < long long, vector < long long >, greater < long long > > Q;
long long ans[6000];
int n;

char* p(int x) {
    if ((x % 100) == 11) return p4;
    if ((x % 100) == 12) return p4;
    if ((x % 100) == 13) return p4;
    if ((x % 10) == 1) return p1;
    if ((x % 10) == 2) return p2;
    if ((x % 10) == 3) return p3;
    return p4;
}

int main() {

    Q.push(1);
    ans[1] = 1;
    for (int i = 2;i <= 5842;++ i) {
        Q.push(ans[i - 1] * 2ll);
        Q.push(ans[i - 1] * 3ll);
        Q.push(ans[i - 1] * 5ll);
        Q.push(ans[i - 1] * 7ll);
        while (Q.top() == ans[i - 1]) Q.pop();
        ans[i] = Q.top();
        Q.pop();
    }

    while ((cin >> n) && (n != 0)) 
        cout << "The " << n << p(n) << " humble number is " << ans[n] << '.' << endl;
    
    return 0;
}
