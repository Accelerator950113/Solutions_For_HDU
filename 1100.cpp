#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long F[32];
long long n;
int t;

void draw(int num, long long index) {
	long long tmp = index;
	int left = 0, right = num - 1;
	long long lindex, rindex;
	while (tmp > (F[left] * F[right])) {
		tmp -= (F[left] * F[right]);
		left ++;
		right --;
	} 
	if (left != 0) {
		putchar('(');
		draw(left, (tmp + F[right] - 1) / F[right]);
		putchar(')');
	}
	putchar('X');
	if (right != 0) {
		putchar('(');
		if ((tmp % F[right]) == 0) draw(right, F[right]);
		else draw(right, tmp % F[right]);
		putchar(')');
	}
}

int main() {

	F[0] = 1ll;
	for (int i = 1;i <= 20;++ i) {
		F[i] = 0ll;
		for (int j = 0;j < i;++ j)
			F[i] += (F[j] * F[i - 1 - j]);
	}
	
	while ((cin >> n) && (n > 0)) {
		t = 1;
		while (n > F[t]) { 
			n -= F[t];
			t ++;
		}
		draw(t,n);
		putchar('\n');
	}
    
    return 0;
}
