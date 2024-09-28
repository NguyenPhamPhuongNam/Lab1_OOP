#include<bits/stdc++.h>
#include <chrono>
using namespace std;
#define int long long
const int INF = numeric_limits<int>::max();
const int nax = (int)(2005);
const int MAXN= (int)(1e6+5);
const int mod =1e9+2277;
const int BASE = (int)(301);
#define all(x) (x).begin(), (x).end()
#define size(x) ((int)x.size())
#define double long double
#define pii pair<int, int>
#define tup tuple<int, int, int>
#define iii pair<pii, int>
#define unsetbit(mask, x) ((mask)&=(~(1 << x)))
#define setbit(mask, x) ((mask)|=(1 << x))
#define reversebit(mask, x) ((mask) ^=(1 << n))
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int d8x[8] = { -1, 1, 0, 0, -1, 1, 1, -1};
const int d8y[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int Trie_sz = 1e6;
#define get_bit(mask, x) ((mask)>>(x)&1)
const int LOG=19;

 
template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
 
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}
// check nam nhuan
bool check(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Lay so ngay trong thang
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return check(year) ? 29 : 28; 
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30; 
    }
    return 31;
}

// Tinh ngay ke tiep
void getNextDay(int &day, int &month, int &year) {
    int daysInMonth = getDaysInMonth(month, year);
    if (day < daysInMonth) {
        day++;
    } else {
        day = 1; 
        if (month == 12) {
            month = 1; 
            year++; 
        } else {
            month++; 
        }
    }
}

// Tinh ngay truoc
void getPreviousDay(int &day, int &month, int &year) {
    if (day > 1) {
        day--;
    } else {
        if (month == 1) {
            month = 12; 
            year--; 
            day = 31; 
        } else {
            month--;
            day = getDaysInMonth(month, year); 
        }
    }
}

// Tinh ngay thu bao nhieu trong nam
int dayOfYear(int day, int month, int year) {
    int totalDays = 0;
    for (int m = 1; m < month; m++) {
        totalDays += getDaysInMonth(m, year);
    }
    totalDays += day; 
    return totalDays;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
     int day, month, year;
    cin >> day;
    cin >> month;
    cin >> year;

    // Tim ngay ke tiep
    int nextDay = day, nextMonth = month, nextYear = year;
    getNextDay(nextDay, nextMonth, nextYear);
    cout << "Ngay ke tiep: " << nextDay << "/" << nextMonth << "/" << nextYear << '\n';

    // Tim ngay truoc do
    int prevDay = day, prevMonth = month, prevYear = year;
    getPreviousDay(prevDay, prevMonth, prevYear);
    cout << "Ngay truoc do: " << prevDay << "/" << prevMonth << "/" << prevYear << '\n';

    // Tinh ngay thu bao nhieu trong nam
    int dayOfYearResult = dayOfYear(day, month, year);
    cout << "Ngay " << day << "/" << month << "/" << year << " la ngay thu " << dayOfYearResult << " trong nam" << '\n';
    exit(0);
    }
    
   


