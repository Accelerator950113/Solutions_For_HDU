#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>

using namespace std;

int p[1024];
int l;
string a,b;
int A[1024],B[1024];
int la,lb;

bool prime(int x) {
	for (int i = 2;(i*i) <= x;++ i)
		if (x % i == 0) return false;
	return true;
}

int main() {

	l = 0;
	for (int i = 2;l <= 1000;++ i)
		if (prime(i)) p[++ l] = i;

	while (cin >> a >> b) {
		if ((strcmp(a.c_str(),"0") == 0) && (strcmp(b.c_str(),"0") == 0)) break;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		int t = 0;
		la = lb = 0;
		while (t < a.size()) {
			while (!isdigit(a[t]))
				t ++;
			la ++;
			while (isdigit(a[t])) {
				A[la] = A[la] * 10 + (a[t] - '0');
				t ++;
			}
		}
		reverse(A + 1,A + la + 1);
		t = 0;
		while (t < b.size()) {
			while (!isdigit(b[t]))
				t ++;
			lb ++;
			while (isdigit(b[t])) {
				B[lb] = B[lb] * 10 + (b[t] - '0');
				t ++;
			}
		}
		reverse(B + 1,B + lb + 1);
		for (int i = 1;i <= 1000;++ i)
			B[i] += A[i];
		for (int i = 1;i <= 1000;++ i) {
			B[i + 1] += (B[i] / p[i]);
			B[i] %= p[i];
		}
		t = 1000;
		while ((B[t] == 0) && (t > 1)) t --;
		printf("%d",B[t]);
		for (int i = t - 1;i > 0;-- i)
			printf(",%d",B[i]);
		printf("\n");
	}
    
    return 0;
}
