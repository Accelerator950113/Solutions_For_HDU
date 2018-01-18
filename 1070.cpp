#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct node {
	char Name[128];
	int c,v,days;
	node() {}
	void readin() {
		scanf("%s%d%d",Name,&c,&v);
		if (v > 1000) days = 5;
		else days = v / 200;
	}
	friend bool operator <(const node &a1,const node &a2) {
		if ((a1.days * a2.c) == (a2.days * a1.c)) return (a1.v > a2.v);
		return ((a1.days * a2.c) > (a2.days * a1.c));
	}
	void show() {
		printf("%s\n",Name);
	}
};

node A[1024];

int main() {

	int T,n;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i = 0;i < n;++ i)
			A[i].readin();
		sort(A,A + n);
		A[0].show();
	}

    return 0;
}
