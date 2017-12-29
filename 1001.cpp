#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

long long n;

void solve(long long n) {
    cout << ((n + 1) * n) / 2 << endl << endl;
}

int main() {
    
    while (cin >> n) {
        solve(n);
    }
    
    return 0;
}
