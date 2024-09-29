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
struct ChuyenBay {
    string maChuyenBay;
    string ngayBay;
    string gioBay;
    string noiDi;
    string noiDen;
};

bool kiemTraMaChuyenBay(const string &machuyen) {
    return regex_match(machuyen, regex("^[A-Z]{2}\\d{3}$")); 
}

bool kiemTraTenDiaDanh(const string &tendiadanh) {
    return regex_match(tendiadanh, regex("^[A-Za-z\\s]+$")); 
}

bool kiemTraNgay(const string &ngaydi) {
    return regex_match(ngaydi, regex("^\\d{2}/\\d{2}/\\d{4}$"));
}

bool kiemTraGio(const string &giodi) {
    return regex_match(giodi, regex("^([01]\\d|2[0-3]):[0-5]\\d$"));
}

void nhapChuyenBay(ChuyenBay &flight) {
    cin >> flight.maChuyenBay;
    while (!kiemTraMaChuyenBay(flight.maChuyenBay)) {
        cin >> flight.maChuyenBay;
    }

    cin >> flight.ngayBay;
    while (!kiemTraNgay(flight.ngayBay)) {
        cin >> flight.ngayBay;
    }

    cin >> flight.gioBay;
    while (!kiemTraGio(flight.gioBay)) {
        cin >> flight.gioBay;
    }

    cin.ignore();
    getline(cin, flight.noiDi);
    while (!kiemTraTenDiaDanh(flight.noiDi)) {
        getline(cin, flight.noiDi);
    }

    getline(cin, flight.noiDen);
    while (!kiemTraTenDiaDanh(flight.noiDen)) {
        getline(cin, flight.noiDen);
    }
}

void inChuyenBay(const ChuyenBay &flight) {
    cout << "Ma chuyen bay: " << flight.maChuyenBay
         << ", Ngay bay: " << flight.ngayBay
         << ", Gio bay: " << flight.gioBay
         << ", Noi di: " << flight.noiDi
         << ", Noi den: " << flight.noiDen << '\n';
}

bool soSanhChuyenBay(const ChuyenBay &flight1, const ChuyenBay &flight2) {
    if (flight1.ngayBay == flight2.ngayBay)
        return flight1.gioBay < flight2.gioBay;
    return flight1.ngayBay < flight2.ngayBay;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    int n;
    cin >> n;

    vector<ChuyenBay> danhSach(n);

    for (int i = 0; i < n; i++) {
        nhapChuyenBay(danhSach[i]);
    }

    sort(all(danhSach), soSanhChuyenBay);

    cout << "\nDanh sach chuyen bay sau khi sap xep:\n";
    for (const auto &flight : danhSach) {
        inChuyenBay(flight);
    }

    string maTimKiem;
    cin >> maTimKiem;
    bool timThay = false;
    for (const auto &flight : danhSach) {
        if (flight.maChuyenBay == maTimKiem) {
            inChuyenBay(flight);
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay chuyen bay voi ma: " << maTimKiem << '\n';
    }

    string noiDiTimKiem, ngayBayTimKiem;
    cin.ignore();
    getline(cin, noiDiTimKiem);
    cin >> ngayBayTimKiem;

    cout << "Danh sach chuyen bay tu " << noiDiTimKiem << " vao ngay " << ngayBayTimKiem << ":\n";
    for (const auto &flight : danhSach) {
        if (flight.noiDi == noiDiTimKiem && flight.ngayBay == ngayBayTimKiem) {
            inChuyenBay(flight);
        }
    }

    string noiDi, noiDen;
    cin.ignore();
    getline(cin, noiDi);
    getline(cin, noiDen);
    int cnt = 0;
    for (const auto &flight : danhSach) {
        if (flight.noiDi == noiDi && flight.noiDen == noiDen) {
            cnt++;
        }
    }

    exit(0);
    }
    
   


