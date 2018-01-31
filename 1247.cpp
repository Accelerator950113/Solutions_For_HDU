#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, x;
string a[65536];
string* tp;
int pos;
bool b[65536];

bool check(int pre, int cnt) {
	if (a[pre].size() >= a[cnt].size())
		return false;
	for (int i = 0; i < a[pre].size(); ++ i)
		if (a[pre][i] != a[cnt][i]) return false;
	return true;
}

bool found(string ss) {
	tp = lower_bound(a, a+n, ss);
	pos = tp - a;
	return (pos != n && a[pos] == ss);
} 

int main() {

    while (cin >> a[n ++]);
    n --;
    sort(a, a+n);
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; ++ i) {
    	x = i+1;
    	while (x < n) {
    		if (check(i, x)) {
    			if (found(a[x].substr(a[i].size(), a[x].size() - a[i].size())))
    				b[x] = true;
    		}
    		else break;
    		++ x;
    	}
    }
    for (int i = 0; i < n; ++ i)
    	if (b[i]) cout << a[i] << endl;

    return 0;
}