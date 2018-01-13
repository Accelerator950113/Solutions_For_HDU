#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int a[4];

void drive() {
	for (int i = 0;i < 3;++ i)
		if (a[i] <= 168) {
			cout << "CRASH " << a[i] << endl;
			return;
		}
	cout << "NO CRASH" << endl;
}

int main() {

	while (cin >> a[0] >> a[1] >> a[2]) 
		drive();

    return 0;
}