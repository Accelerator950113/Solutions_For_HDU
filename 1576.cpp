#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define M 9973

using namespace std;

int k, a, b, n, tp;

int main() {

    cin >> n;
    while (cin >> n >> b) {
        b %= M;
        k = 0, tp = 0;
        while (tp != n) {
            ++ k;
            tp = (tp + b) % M;
        }
        cout << k % M << endl;
    }

    return 0;
}