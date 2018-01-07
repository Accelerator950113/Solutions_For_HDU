#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define Lowbit(x) ((x) & (-x))

using namespace std;

int main() {

	int x;
	while ((cin >> x) && (x != 0)) 
		cout << Lowbit(x) << endl;

    return 0;
}
