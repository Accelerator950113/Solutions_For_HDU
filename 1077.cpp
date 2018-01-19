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

using namespace std;

struct point {
	double x,y;
	point() {}
	void readin() {
		scanf("%lf%lf",&x,&y);
	}
	double dis(const point &a1) {
		return sqrt((x - a1.x) * (x - a1.x) + (y - a1.y) * (y - a1.y));
	}
	double getmo() {
		return sqrt(x*x + y*y);
	}
	void add(const point &a1) {
		x += a1.x;
		y += a1.y;
	} 
	void multi(double xx) {
		x *= xx;
		y *= xx;
	}
	void sub(const point &a1) {
		x -= a1.x;
		y -= a1.y;
	}
	void rev() {
		swap(x,y);
		x *= -1;
	}
};

int n;
point A[512];
point mid,v,p;
double t;

int check() {
	int ts = 0;
	for (int i = 1;i <= n;++ i)
		if (p.dis(A[i]) < 1.0001) ts ++;
	return ts;
}

int main() {

	int test;
	scanf("%d",&test);
	while (test --) {
		scanf("%d",&n);
		for (int i = 1;i <= n;++ i)
			A[i].readin();
		int ans = 1;
		for (int i = 1;i <= n;++ i)
			for (int j = 1;j < i;++ j) 
				if (A[i].dis(A[j]) < 2) {
					mid = A[i];
					mid.add(A[j]);
					mid.multi(0.5);
					v = A[j];
					v.sub(A[i]);
					v.rev();
					t = v.getmo();
					v.multi(1/t);
					t = sqrt(1 - (t/2)*(t/2));
					v.multi(t);
					p = mid;
					p.add(v);
					ans = max(ans,check());
					p = mid;
					p.sub(v);
					ans = max(ans,check());
				}
		printf("%d\n",ans);
	}
    
    return 0;
}
