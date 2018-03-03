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

struct student {
    string name;
    int score, id;
    void readin(int _id) {
        cin >> name >> score;
        id = _id;
    }
    void write() {
        cout << name << " " << score << endl;
    }
    friend bool operator <(const student &a1, const student &a2) {
        if (a1.score == a2.score)
            return (a1.id < a2.id);
        else
            return (a1.score > a2.score);
    }
    friend bool operator ==(const student &a1, const student &a2) {
        return ((a1.score == a2.score) && (a1.name == a2.name));
    }
};

int n;
student a[512], b[512];

bool checkStable() {
    for (int i = 0;i < n; ++ i)
        if (!(a[i] == b[i]))
            return false;
    return true;
}

bool checkRight() {
    for (int i = 1; i < n; ++ i)
        if (b[i].score > b[i-1].score)
            return false;
    return true;
}

int main() {
    
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; ++ i)
            a[i].readin(i);
        for (int i = 0; i < n; ++ i)
            b[i].readin(i);
        sort(a, a+n);
        if (checkStable()) 
            cout << "Right" << endl;
        else {
            if (checkRight()) 
                cout << "Not Stable" << endl;
            else
                cout << "Error" << endl;
            for (int i = 0; i < n; ++ i)
                a[i].write();
        }
    }

    return 0;
}