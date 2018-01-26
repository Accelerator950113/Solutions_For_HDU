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

using namespace std;

int n;
char ch;
bool fst = true;

void output(int kg, int x) {
	if (x < 1) return;
	if (x == 1) {
		for (int i = 0; i < kg; ++ i)
			cout << " ";
		cout << ch << endl;
		return;
	}
	output(kg + 1, x - 2);
	for (int i = 0; i < kg; ++ i)
		cout << " ";
	cout << ch;
	for (int i = 0; i < x-2; ++ i)
		cout << " ";
	cout << ch << endl;

}

int main() {

	while (cin >> ch >> n) {
		if (fst) fst = false;
		else cout << endl;
		output(1, 2*n-3);
		for (int i = 1; i < 2*n; ++ i)
			cout << ch;
		cout << endl;
	}

    return 0;
}
