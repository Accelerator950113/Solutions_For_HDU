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

struct Student {
	string Name;
	int solved, t;

	friend bool operator <(const Student &a1, const Student &a2) {
		if ((a1.solved == a2.solved) && (a1.t == a2.t)) return (a1.Name < a2.Name);
		if (a1.solved == a2.solved) return (a1.t < a2.t);
		return (a1.solved > a2.solved); 
	}
};

string str, buf;
Student S[256];
int n, m, r = 0;
int t1, c1;
char ch;

int main() {

	cin >> n >> m;
	while (cin >> buf) {
		S[++ r].Name = buf;
		S[r].solved = S[r].t = 0;
		for (int i = 1; i <= n; ++ i) {
			cin >> buf;
			stringstream ts;
			ts << buf;
			ts >> t1;
			if (ts >> ch >> c1) {
				S[r].solved ++;
				S[r].t += (t1 + c1*m); 
				continue;
			}
			if (t1 > 0) {
				S[r].solved ++;
				S[r].t += t1;
			}
		}
	}
	sort(S + 1, S + r + 1);
	for (int i = 1; i <= r; ++ i)
		printf("%-10s %2d %4d\n", S[i].Name.c_str(), S[i].solved, S[i].t);

    return 0;
}
