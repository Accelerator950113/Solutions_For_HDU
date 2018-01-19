#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define Lowbit(x) ((x) & (-x))
#define LL long long 

using namespace std;

queue < LL > Q;
LL N;
int tot;

int main() {

	cin >> N;
	while (cin >> N) {
		while (!Q.empty()) 
			Q.pop();
		tot = 0;
		while (Lowbit(N) != N) {
			if (N & 1) {
				tot ++;
				Q.push(N);
				N = 3 * (N >> 1) + 2;
			}
			else N >>= 1;
		}
		if (tot == 0) puts("No number can be output !");
		else {
			while (tot > 1) {
				tot --;
				cout << Q.front() << ' ';
				Q.pop();
			}
			cout << Q.front() << endl;
			Q.pop();
		}
	}
    
    return 0;
}
