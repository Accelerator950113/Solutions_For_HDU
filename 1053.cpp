#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define getmin(x,y) ((x < y) ? (x) : (y))

using namespace std;

struct node {
	int num,key;
	char s[256];
	node() {}
	node(int _k,char _x) {
		num = 1;
		key = _k;
		s[1] = _x;
	}
	void add(char _x) {
		s[++ num] = _x;
	}
	friend bool operator <(const node &a1,const node &a2) {
		return (a1.key > a2.key);
	}
};

priority_queue < node > Q;
char str[1048576];
int n;
int H[512];
int len[512];

int main() {

	while (scanf("%s",str) != EOF) {
		if (strcmp(str,"END") == 0) break;
		n = strlen(str);
		memset(H,0,sizeof(H));
		memset(len,0,sizeof(len));
		for (int i = 0;i < n;++ i)
			H[str[i]] ++;
		while (!Q.empty()) 
			Q.pop();
		for (int i = 0;i < 256;++ i)
			if (H[i] > 0) Q.push(node(H[i],(char)i));
		node q1,q2;
		while (Q.size() > 1) {
			q1 = Q.top();
			Q.pop();
			q2 = Q.top();
			Q.pop();
			for (int i = 1;i <= q2.num;++ i)
				q1.add(q2.s[i]);
			q1.key += q2.key;
			for (int i = 1;i <= q1.num;++ i)
				len[q1.s[i]] ++;
			Q.push(q1);
		}
		int ans = 0;
		for (int i = 0;i < n;++ i)
			ans += len[str[i]];
		if (ans == 0) ans = n;
		printf("%d %d %.1lf\n",n*8,ans,(double)(n*8)/(double)ans);
	}

    return 0;
}
