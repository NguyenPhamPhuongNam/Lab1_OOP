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
struct PhanSo {
    int tu; 
    int mau; 
};

PhanSo rutGon(PhanSo ps) {
    ps.tu /= __gcd(ps.tu, ps.mau);
    ps.mau /=__gcd(ps.tu, ps.mau);
    return ps;
}
PhanSo nhapPhanSo() {
    PhanSo ps;
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    cout << "Nhap mau so: ";
    cin >> ps.mau;
    if (ps.mau == 0) {
        cout << "Phansokhongxacdinh" <<"\n";
    }
    return ps;
}

PhanSo congPhanSo(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau + b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    return rutGon(kq);
}

PhanSo truPhanSo(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau - b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    return rutGon(kq);
}

PhanSo nhanPhanSo(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.tu;
    kq.mau = a.mau * b.mau;
    return rutGon(kq);
}

PhanSo chiaPhanSo(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau;
    kq.mau = a.mau * b.tu;
    return rutGon(kq);
}

void xuatPhanSo(PhanSo ps) {
    (ps.mau == 1) ? (cout << ps.tu): (cout << ps.tu << "/" << ps.mau);
    }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:" << endl;
    ps1 = nhapPhanSo();
    
    cout << "Nhap phan so thu hai:" << endl;
    ps2 = nhapPhanSo();

    PhanSo tong = congPhanSo(ps1, ps2);
    PhanSo hieu = truPhanSo(ps1, ps2);
    PhanSo tich = nhanPhanSo(ps1, ps2);
    PhanSo thuong = chiaPhanSo(ps1, ps2);

    cout << "Tong hai phan so: ";
    xuatPhanSo(tong);
    cout << endl;

    cout << "Hieu hai phan so: ";
    xuatPhanSo(hieu);
    cout << endl;

    cout << "Tich hai phan so: ";
    xuatPhanSo(tich);
    cout << endl;

    cout << "Thuong hai phan so: ";
    xuatPhanSo(thuong);
    cout << endl;
    
    exit(0);
}


