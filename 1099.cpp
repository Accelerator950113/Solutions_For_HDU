#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#define LL long long

using namespace std;

LL gcd(LL x,LL y) {
	if (x % y == 0) return y;
	else return gcd(y,x % y);
}

LL lcm(LL x,LL y) {
	return (x / gcd(x,y) * y);
}

int getlen(LL x) {
	if (x == 0) return 1;
	int ts = 0;
	while (x > 0) {
		x /= 10;
		ts ++;
	}
	return ts;
}

struct frac {
	LL zs,fz,fm;
	frac() {}
	frac(int _z,int _m) {
		fz = (LL)_z;
		fm = (LL)_m;
		zs = fz / fm;
		fz %= fm;
	}
	friend frac operator +(const frac &a1,const frac &a2) {
		frac a3;
		a3.zs = a1.zs + a2.zs;
		a3.fm = lcm(a1.fm,a2.fm);
		a3.fz = a1.fz * (a3.fm / a1.fm) + a2.fz * (a3.fm / a2.fm);
		a3.zs += (a3.fz / a3.fm);
		a3.fz %= a3.fm;
		LL tmp = gcd(a3.fz,a3.fm);
		a3.fz /= tmp;
		a3.fm /= tmp;
		return a3;
	}
	void show() {
		if (fz == 0) {
			cout << zs << endl;
			return;
		}
		int l1 = getlen(zs);
		int l2 = getlen(fm);
		for (int i = 0;i <= l1;++ i)
			cout << ' ';
		cout << fz << endl;
		cout << zs << ' ';
		for (int i = 0;i < l2;++ i)
			cout << '-';
		cout << endl;
		for (int i = 0;i <= l1;++ i)
			cout << ' ';
		cout << fm << endl;
	}
}; 

frac f[64];
int n;

int main() {

	while (cin >> n) {
		f[0] = frac(0,1);
		f[1] = frac(1,1);
		for (int i = 2;i <= n;++ i)
			f[i] = f[i - 1] + frac(n,n-i+1);
		f[n].show();
	}
    
    return 0;
}
