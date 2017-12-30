#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int A,B;

int gcd(int x,int y) {
    if ((x % y) == 0) return y;
    else return gcd(y,x % y);
}

int main() {

    while (scanf("%d%d",&A,&B) == 2) {
        printf("%10d%10d    ",A,B);
        if (gcd(A,B) == 1) printf("Good Choice\n");
        else printf("Bad Choice\n");
        printf("\n");
    }
    
    return 0;
}
