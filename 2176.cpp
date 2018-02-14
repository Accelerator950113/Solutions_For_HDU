#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int a[262144];
int m, key, ans;

int main() {
    
    while (scanf("%d", &m) == 1 && m != 0) {
    	for (int i = 0; i < m; ++ i)
    		scanf("%d", a+i);
    	key = 0;
    	for (int i = 0; i < m; ++ i)
    		key ^= a[i];
    	if (key == 0) 
    		printf("No\n");
    	else {
    		printf("Yes\n");
    		for (int i = 0; i < m; ++ i) {
    			ans = a[i] - (a[i] & key) + (key - (a[i] & key));
    			if (ans < a[i])
    				printf("%d %d\n", a[i], ans);
    		}
    	}
    }

    return 0;
}