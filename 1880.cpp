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

struct word {
    string s1, s2;
    friend bool operator <(const word &a1, const word &a2) {
        return (a1.s1 < a2.s1);
    }
};

int m = 0;
word d1[101072], d2[101072];
string buf, s1, s2;
int n;

string work1(string x) {
    word y;
    y.s1 = x;
    int pos = (lower_bound(d1, d1+m, y) - d1);
    if (pos == m)
        return "what?";
    if (d1[pos].s1 == x)
        return d1[pos].s2;
    else
        return "what?";
}

string work2(string x) {
    word y;
    y.s1 = x;
    int pos = (lower_bound(d2, d2+m, y) - d2);
    if (pos == m)
        return "what?";
    if (d2[pos].s1 == x)
        return d2[pos].s2;
    else
        return "what?";
}

int main() {
    
    while (getline(cin, buf)) {
        if (buf == "@END@")
            break;
        size_t found = buf.find("]");
        s1 = buf.substr(1, found-1);
        s2 = buf.substr(found+2);
        d1[m].s1 = s1, d1[m].s2 = s2;
        d2[m].s1 = s2, d2[m].s2 = s1;
        m ++;
    }
    sort(d1, d1+m);
    sort(d2, d2+m);
    getline(cin, buf);
    stringstream ss;
    ss << buf;
    ss >> n;
    while (n --) {
        getline(cin, buf);
        if (buf[0] == '[') {
            s1 = buf.substr(1, buf.size()-2);
            cout << work1(s1) << endl;
        }
        else 
            cout << work2(buf) << endl;
    }

    return 0;
}