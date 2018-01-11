#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#define f(x) ((x) * (x))
#define LL long long
#define inf 1e20

using namespace std;

struct point {
	double x,y;
	point () {}
	friend double operator -(const point &a1,const point &a2) {
		return sqrt(f(a1.x - a2.x) + f(a1.y - a2.y));
	}
};

int n;
point A[128];
double dis[128];
bool v[128];

int main() {

	while (cin >> n) {
		for (int i = 1;i <= n;++ i) 
			cin >> A[i].x >> A[i].y;
		for (int i = 1;i <= n;++ i) {
			dis[i] = inf;
			v[i] = false;
		}
		dis[1] = 0;
		for (int i = 1;i < n;++ i) {
			double min = inf;
			int mid = 0;
			for (int j = 1;j <= n;++ j)
				if ((!v[j]) && (dis[j] < min)) {
					min = dis[j];
					mid = j;
				}
			v[mid] = true;
			for (int j = 1;j <= n;++ j)
				if ((!v[j]) && (A[mid] - A[j] < dis[j])) dis[j] = A[mid] - A[j];
		}
		double ans = 0;
		for (int i = 1;i <= n;++ i)
			ans += dis[i];
		printf("%.2lf\n",ans);
	}

    return 0;
}
