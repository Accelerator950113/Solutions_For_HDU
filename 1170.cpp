#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXM 131072

using namespace std;

int T,a,b;
char ch;

int main() {

	scanf("%d",&T);
	while (T --) {
		ch = getchar();
		while ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/'))
			ch = getchar();
		scanf("%d%d",&a,&b);
		switch(ch) {
			case '+' : {
				printf("%d\n",a + b);
				break;
			}
			case '-' : {
				printf("%d\n",a - b);
				break;
			}
			case '*' : {
				printf("%d\n",a * b);
				break;
			}
			default : {
				if ((a % b) == 0) printf("%d\n",a / b);
				else printf("%.2lf\n",(double)a / (double)b);
				break;
			}
		}
	}
    
    return 0;
}
