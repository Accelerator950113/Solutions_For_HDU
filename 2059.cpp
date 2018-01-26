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
#include <set>
#include <bitset>
#include <sstream>

using namespace std;

int l;
int n, c, t;
int vr, vt1, vt2;
int p[128];
double f[128];
double rab;

double calc(int dis) {
	if (dis <= c) return ((double)dis / (double)vt1);
	return (((double)c / (double)vt1) + ((double)(dis-c) / (double)vt2));
}

int main() {

	while (cin >> l) {
		cin >> n >> c >> t;
		cin >> vr >> vt1 >> vt2;
		for (int i = 1; i <= n; ++ i)
			cin >> p[i];
		p[0] = 0, p[n+1] = l;
		rab = (double)l / (double)vr;
		for (int i = 1; i <= n+1; ++ i) {
			f[i] = calc(p[i] - 0);
			for (int j = 1; j < i; ++ j)
				if (f[j] + calc(p[i]-p[j]) + t < f[i])
					f[i] = f[j] + calc(p[i]-p[j]) + t;
		}
		if (f[n+1] < rab) cout << "What a pity rabbit!" << endl;
		else cout << "Good job,rabbit!" << endl;
	}

    return 0;
}
