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

string buf;
string ans;
int a;
char ch;

bool checkString() {
    for (int i = 0; i < buf.size(); ++ i)
        if ((buf[i] != '.') && (!isdigit(buf[i])))
            return false;
    int pre = -1, num = 0;
    for (int i = 0; i < buf.size(); ++ i)
        if (buf[i] == '.') {
            if ((i-pre <= 1) || (i-pre > 4))
                return false;
            pre = i;
            num ++;
        }
    if (num != 3 || pre == buf.size()-1)
        return false;
    return true;
}

int main() {
    
    while (getline(cin, buf)) {
        stringstream ss;
        ss << buf;
        if (checkString()) {
            ss >> a >> ch;
            if (a > 255)
                ans = "NO";
            else {
                ss >> a >> ch;
                if (a > 255)
                    ans = "NO";
                else {
                    ss >> a >> ch;
                    if (a > 255)
                        ans = "NO";
                    else {
                        ss >> a;
                        if (a > 255)
                            ans = "NO";
                        else
                            ans = "YES";
                    }
                }
            }
        }
        else
            ans = "NO";
        cout << ans << endl;
    }

    return 0;
}