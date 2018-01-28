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
#include <set>
#include <bitset>
#include <sstream>

using namespace std;

map < string, int > M;
string buf, tmp;

int main() {

    M.clear();
    while (getline(cin, buf)) {
        if ((buf.size() < 1) || (!isalpha(buf[0]))) 
            break;
        tmp = "";
        for (int i = 0; i < buf.size(); ++ i) {
            tmp = tmp + buf[i];
            M[tmp] ++;
        }
    }

    while (cin >> buf) 
        cout << M[buf] << endl;

    return 0;
}