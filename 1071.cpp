#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#define LL long long

using namespace std;

int T;
double x1,x2,x3,_y1,y2,y3;
double a,b,c;

double F(double x) {
	return (a*x*x*x + b*x*x + c*x);
}

int main() {

	cin >> T;
	while (T --) {
		cin >> x1 >> _y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		double h0 = x1*x1*(x2-x3) + x1*(x3*x3-x2*x2) + (x2*x2*x3 - x3*x3*x2);
		double h1 = _y1*(x2-x3) + x1*(y3-y2) + (y2*x3 - y3*x2);
		double h2 = x1*x1*(y2-y3) + _y1*(x3*x3-x2*x2) + (x2*x2*y3 - x3*x3*y2);
		double h3 = x1*x1*(x2*y3-x3*y2) + x1*(x3*x3*y2-x2*x2*y3) + _y1*(x2*x2*x3 - x3*x3*x2);
		a = h1 / h0;
		a /= 3.0;
		b = h2 / h0;
		b /= 2.0;
		c = h3 / h0;
		printf("%.2lf\n",F(x3) - F(x2) - (x3-x2)*(y2+y3)/2.0);
	}

    return 0;
}
