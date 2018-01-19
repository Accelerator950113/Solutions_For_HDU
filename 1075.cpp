#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>

using namespace std;

map < string , string > M;
char tmp[128],tmp2[128],ch;
int l;

void getword() {
	l = 0;
	ch = getchar();
	while (!isalpha(ch)) {
		putchar(ch);
		ch = getchar();
	}
	while (isalpha(ch)) {
		tmp[l ++] = ch;
		ch = getchar();
	}
	tmp[l] = '\0';
}

int main() {

	M.clear();
	while (true) {
		scanf("%s",tmp);
		if (strcmp(tmp,"START") == 0) continue;
		if (strcmp(tmp,"END") == 0) break;
		scanf("%s",tmp2);
		M[string(tmp2)] = string(tmp);
	}
	ch = getchar();
	while (ch != 'S')
		ch = getchar();
	while (ch != '\n')
		ch = getchar();
	while (true) {
		getword();
		if (strcmp(tmp,"END") == 0) break;
		if (!M.count(string(tmp))) printf("%s",tmp);
		else printf("%s",M[string(tmp)].c_str());
		putchar(ch);
	}
    
    return 0;
}
