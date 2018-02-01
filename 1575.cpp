#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define MOD 9973

using namespace std;

class Matrix {
	private:
		int n;
		int a[16][16];
	public:
		Matrix() {}
		void readin(int size) {
			n = size;
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= n; ++ j)
					scanf("%d", &a[i][j]);
		}
		friend Matrix operator *(const Matrix &a1, const Matrix &a2) {
			Matrix a3;
			a3.n = a1.n;
			for (int i = 1; i <= a1.n; ++ i)
				for (int j = 1; j <= a1.n; ++ j) {
					a3.a[i][j] = 0;
					for (int k = 1; k <= a1.n; ++ k)
						a3.a[i][j] = (a3.a[i][j] + a1.a[i][k] * a2.a[k][j]) % MOD;
				}
			return a3;
		}
		int Tr() {
			int ts = 0;
			for (int i = 1; i <= n; ++ i)
				ts = (ts + a[i][i]) % MOD;
			return ts;
		}
};

Matrix A, B;
int t, s, K;

Matrix cf(Matrix x, int y) {
	if (y == 1) return x;
	Matrix C = cf(x, y / 2);
	C = C * C;
	if (y & 1) C = C * x;
	return C;
}

int main() {

   	scanf("%d", &t);
   	while (t --) {
   		scanf("%d%d", &s, &K);
   		A.readin(s);
   		B = cf(A, K);
   		printf("%d\n", B.Tr());
   	}

    return 0;
}