#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char s[1048576];
int sum;

int work(int x) {
    int ts = 0;
    while (x > 0) {
        ts = ts + (x % 10);
        x /= 10;
    }
    return ts;
}

int main() {

    while (true) {
        gets(s);
        if (s[0] == '0') break;
        sum = 0;
        for (int i = 0;i < strlen(s);++ i) 
            sum += (s[i] - '0');
        while (sum > 9) sum = work(sum);
        printf("%d\n",sum);
    }
    
    return 0;
}
