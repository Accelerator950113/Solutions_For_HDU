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

using namespace std;

class constant {
	private:
		int days[2][13];
	public:
		constant() {
			memset(days,0,sizeof(days));
			for (int i = 1;i <= 12;++ i)
				days[0][i] = days[1][i] = 30;
			for (int i = 1;i < 8;i += 2)
				days[0][i] = days[1][i] = 31;
			for (int i = 8;i < 13;i += 2)
				days[0][i] = days[1][i] = 31;
			days[0][2] = 28;
			days[1][2] = 29;
		}
		int getdays(int y, int m) {
			if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))) return days[1][m];
			else return days[0][m];
		}
} C;

class date {
	private:
		int year, month, day;
	public:
		date() {}
		date(int _y,int _m,int _d) {
			year = _y, month = _m, day = _d;
		}
		void readin() {
			scanf("%d%d%d",&year,&month,&day);
		}
		void nextDay() {
			day ++;
			if (day > C.getdays(year, month)) {
				day = 1;
				month ++;
				if (month > 12) {
					month = 1;
					year ++;
				}
			}
		}
		bool canNext() {
			month ++;
			if (month > 12) {
				year ++;
				month = 1;
			}
			if (day > C.getdays(year, month)) {
				if (month == 1) {
					month = 12;
					year --;
				}
				else month --;
				return false;
			}
			return true;
		}
		friend bool operator ==(const date &a1, const date &a2) {
			return ((a1.year == a2.year) && (a1.month == a2.month) && (a1.day == a2.day));
		}
		friend bool operator <(const date &a1, const date &a2) {
			if (a1.year == a2.year) {
				if (a1.month == a2.month) return (a1.day < a2.day);
				else return (a1.month < a2.month);
			}
			else return (a1.year < a2.year);
		}
		friend bool operator >(const date &a1, const date &a2) {
			if (a1.year == a2.year) {
				if (a1.month == a2.month) return (a1.day > a2.day);
				else return (a1.month > a2.month);
			}
			else return (a1.year > a2.year);
		}
};

int m,pos;
date A[65536],*p,dd,tmp;
bool ans[65536];
bool flag;

int main() {

	dd = date(2001,11,4);
	A[0] = date(1900,1,1);
	m = 1;
	for (int i = 1;!(A[m - 1] == dd);++ i) {
		A[m] = A[m - 1];
		A[m].nextDay();
		m ++;
	}
	memset(ans,0,sizeof(ans));
	for (int i = m - 2;i >= 0;-- i) {
		tmp = A[i];
		flag = tmp.canNext();
		if ((flag) && (!(tmp > dd))) {
			p = lower_bound(A, A + m, tmp);
			pos = (p - A);
			ans[i] = !(ans[i + 1] && ans[pos]);
		}
		else ans[i] = !ans[i + 1];
	}
    
	int T;
	scanf("%d",&T);
	while (T --) {
		tmp.readin();
		p = lower_bound(A, A + m, tmp);
		pos = (p - A);
		if (ans[pos]) puts("YES");
		else puts("NO");
	}

    return 0;
}
