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
int pw[nax];
void precal() {
    pw[0] = 1;
    for (int i = 1; i < nax; ++i) {
        pw[i] = BASE * pw[i - 1];
    }
}

int hashArray(const vector<int>& a) {
    int h = 0;
    for (int val : a) {
        h = BASE * h + val;
    }
    return h;
}

void countOccurrences(const vector<int>& a, const vector<int>& b) {
    vector<int> idx; 
    int hashA = hashArray(a); 

    int hashB = 0;
    for (int i = 0; i < size(a); ++i) {
        hashB = BASE * hashB + b[i];
    }

    if (hashB == hashA) {
        idx.push_back(0); 
    }


    for (int i = 1; i <= size(b) - size(a); ++i) {
        hashB = BASE * hashB - b[i - 1] * pw[size(a)] + b[i + size(a) - 1]; 
        if (hashB == hashA) {
            idx.push_back(i); 
        }
    }

    cout << "So lan xuat hien cua a trong b: " << size(idx) << '\n';
    cout << "Cac chi so bat dau: ";
    for (int index : idx) {
        cout << index << " ";
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
     precal(); 

    int sizeA, sizeB;
    cin >> sizeA>> sizeB;
    vector<int> a(sizeA);
    for (int i = 0; i < sizeA; i++) {
        cin >> a[i];
    }
    vector<int> b(sizeB);
    for (int i = 0; i < sizeB; i++) {
        cin >> b[i];
    }
    countOccurrences(a, b);
    exit(0);
    }
    
   


