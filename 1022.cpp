#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

char In[131072],Out[131072];
char Stack[131072];
int top;
bool flag;
bool ans[131072]; // in : true, out : false
int n,l;

int main() {

    while (scanf("%d",&n) == 1) {
        for (int i = 0;i <= n;++ i) In[i] = getchar();
        for (int i = 0;i <= n;++ i) Out[i] = getchar();
        top = 0, l = 0, flag = true;
    	for (int i = 1, j = 1;j <= n;++ j) {
    		if ((top > 0) && (Stack[top] == Out[j])) {
    			ans[++ l] = false;
    			top --;
    			continue;
    		}
    		while ((i <= n) && (In[i] != Out[j])) {
    			Stack[++ top] = In[i ++];
    			ans[++ l] = true;
    		}
    		if (i > n) {
    			flag = false;
    			break;
    		}
    		else {
    			ans[++ l] = true;
    			ans[++ l] = false;
    			i ++;
    		}
    	}
    	if (flag) {
    		printf("Yes.\n");
    		for (int i = 1;i <= l;++ i) 
    			if (ans[i]) printf("in\n");
    			else printf("out\n");
    		printf("FINISH\n");
    	}
    	else printf("No.\nFINISH\n");
    }
    
    return 0;
}
