#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#define MOD 9973

using namespace std;

map < int, int > M;

int n, T, x, ans;

int main() {

   	scanf("%d", &T);
   	while (T --) {
   		scanf("%d", &n);
   		M.clear();
   		while (n --) {
   			scanf("%d", &x);
   			M[x] ++;
   		}
   		ans = 0;
   		for (map < int, int > :: iterator it = M.begin(); it != M.end(); ++ it)
   			ans = max(ans, it -> second);
   		printf("%d\n", ans);
   	}

    return 0;
}