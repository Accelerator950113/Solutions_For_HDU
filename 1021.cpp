#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define MAXN 1000000
#define MOD 3

using namespace std;

int F[1048576];
int n;

int main() {

	F[0] = 7 % MOD;
    F[1] = 11 % MOD;
    for (int i = 2;i <= MAXN;++ i) 
        F[i] = (F[i - 1] + F[i - 2]) % MOD;

    while (scanf("%d",&n) == 1) {
        if (F[n] == 0) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}
