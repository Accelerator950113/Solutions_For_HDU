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

struct room {
	int id, n, c;
	void read() {
		cin >> id >> n >> c;
	}
	friend bool operator <(const room &a1, const room &a2) {
		return (a1.c < a2.c);
	}
};

room R[128];
int T, n, Q, tp;

bool find(int x) {
	for (int i = 0; i < n; ++ i)
        if (R[i].n >= x) {
            R[i].n -= x;
            cout << R[i].id << endl;
            return true;
        }
    return false;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin >> T;
    while (T --) {
    	cin >> n;
    	for (int i = 0; i < n; ++ i)
    		R[i].read();
    	sort(R, R+n);
    	cin >> Q;
        while (Q --) {
            cin >> tp;
            if (!find(tp))
                cout << "sorry" << endl;
        }
    }

    return 0;
}