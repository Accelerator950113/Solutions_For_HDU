#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int N;

int cf(int x,int y) {
    if (y == 1) return (x % 10);
    int tmp = cf(x,y / 2);
    tmp = (tmp * tmp) % 10;
    if (y & 1) tmp = (tmp * (x % 10)) % 10;
    return tmp;
}

int main() {

    cin >> T;
    while (T --) {
        cin >> N;
        cout << cf(N,N) << endl;
    }  
    
    return 0;
}
