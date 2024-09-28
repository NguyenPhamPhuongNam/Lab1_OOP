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

void rutGonPhanSo(int &tu, int &mau) {
    int u=__gcd(tu, mau);
    tu /= u;
    mau /= u;
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}
int soSanhPhanSo(int tu1, int mau1, int tu2, int mau2) {
    int ketQua = tu1 * mau2 - tu2 * mau1;
    if (ketQua > 0){
        return 1;
    } 
    else if (ketQua < 0){
        return -1; 
    }
    else{
        return 0;
    } 
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    int tu1, mau1, tu2, mau2;
    cin >> tu1 >> mau1;
    cin >> tu2 >> mau2;

    rutGonPhanSo(tu1, mau1);
    rutGonPhanSo(tu2, mau2);
    int ketQua = soSanhPhanSo(tu1, mau1, tu2, mau2);
    if (ketQua > 0){
        cout << "Phan so lon nhat la: " << tu1 << "/" << mau1 << '\n';
    }
    else if (ketQua < 0){
        cout << "Phan so lon nhat la: " << tu2 << "/" << mau2 << '\n';
    }
    else{
        cout << "hai phan so bang nhau" << '\n';
    }
    exit(0); 
    }
