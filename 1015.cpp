#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int N,Target;
int S[32];
int Answer[8];

void GetSet() {
	N = 0;
	char ch = getchar();
	while ((ch < 'A') || (ch > 'Z')) ch = getchar();
	while (('A' <= ch) && (ch <= 'Z')) {
		++ N;
		S[N] = (ch - 'A') + 1;
		ch = getchar();
	}
}

int cf(int x,int y) {
	int ts = 1;
	for (int ii = 0;ii < y;++ ii) ts *= x;
	return ts;
}

bool solve() {
	for (int i = N;i > 0;-- i)
		for (int j = N;j > 0;-- j)
			if (i != j) 
				for (int k = N;k > 0;-- k)
					if ((i != k) && (j != k))
						for (int l = N;l > 0;-- l)
							if ((i != l) && (j != l) && (k != l))
								for (int m = N;m > 0;-- m)
									if ((i != m) && (j != m) && (k != m) && (l != m) && 
										((S[i] - cf(S[j],2) + cf(S[k],3) - cf(S[l],4) + cf(S[m],5)) == Target)) {
										Answer[1] = S[i];
										Answer[2] = S[j];
										Answer[3] = S[k];
										Answer[4] = S[l];
										Answer[5] = S[m];
										return true;
									}
	return false;
}

void printAnswer() {
	for (int i = 1;i < 6;++ i)
		putchar(Answer[i] + 'A' - 1);
	putchar('\n');
}

int main() {

    while (scanf("%d",&Target) == 1) {
    	if (Target == 0) break;
        GetSet();
        sort(S + 1,S + N + 1);
        if (solve()) printAnswer();
        else printf("no solution\n");
    }
    
    return 0;
}
