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

struct Student {
    string name;
    double mathScore;
    double literatureScore;
    double foreignLanguageScore;
    double averageScore;
    string classification;
};

bool isValidName(const string &name) {
    for (char c : name) {
        if (isdigit(c)) {
            return false;
        }
    }
    return !name.empty();
}

// ham kiem tra diem
double getValidScore(const string &subject) {
    double score;
    while (1) {
        cout << "Nhap diem " << subject << ": " << flush; 
        cin >> score;
        if (cin.fail() || score < 0 || score > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Diem khong hop le, vui long nhap lai!" << '\n';
            break;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break;
        }
    }
    return score;
}

// Hàm phan loai hoc sinh
string classifyStudent(double averageScore) {
    if (averageScore >= 9) return "Xuat sac";
    if (averageScore >= 8) return "Gioi";
    if (averageScore >= 6.5) return "Kha";
    if (averageScore >= 5) return "Trung binh";
    return "Yeu";
}

// Hàm nhap thong tin hoc sinh
void inputStudents(vector<Student> &students, int n) {
    for (int i = 0; i < n; ++i) {
        Student student;
        while (1) { 
            cout << "Nhap ho ten hoc sinh thu " << (i + 1) << ": " << flush; 
            getline(cin, student.name);
            if (isValidName(student.name)) break;
            else cout << "Ten khong hop le, vui long nhap lai!\n";
        }

        student.mathScore = getValidScore("Toan");
        student.literatureScore = getValidScore("Van");
        student.foreignLanguageScore = getValidScore("Ngoai Ngu");

        student.averageScore = (2 * student.mathScore + student.literatureScore + student.foreignLanguageScore) / 4.0;
        student.classification = classifyStudent(student.averageScore);
        students.push_back(student);
    }
}

void findTopStudent(const vector<Student> &students) {
    double maxAvgScore = -1;
    Student topStudent;

    for (const auto &student : students) {
        if (student.averageScore > maxAvgScore) {
            maxAvgScore = student.averageScore;
            topStudent = student;
        }
    }

    cout << "Hoc sinh co diem trung binh cao nhat: " << topStudent.name 
         << " voi diem trung binh " << fixed << setprecision(2) << topStudent.averageScore
         << " (Phan loai: " << topStudent.classification << ")" << '\n';
}

// Ham tim kiem hoc sinh
void searchStudent(const vector<Student> &students) {
    string keyword;
    cout << "Nhap tu khoa tim kiem: " << flush; 
    getline(cin, keyword);

    cout << "Ket qua tim kiem:\n";
    for (const auto &student : students) {
        if (student.name.find(keyword) < size(student.name)) {
            cout << student.name << " - Diem trung binh: " 
                 << fixed << setprecision(2) << student.averageScore 
                 << " (Phan loai: " << student.classification << ")" << '\n';
        }
    }
}

// Ham xuat danh sach hoc sinh co diem toan thap nhat
void findLowestMathScore(const vector<Student> &students) {
    double minMathScore = 11; 
    vector<Student> lowestStudents;

    for (const auto &student : students) {
        if (student.mathScore < minMathScore) {
            minMathScore = student.mathScore;
            lowestStudents.clear();
            lowestStudents.push_back(student);
        } else if (student.mathScore == minMathScore) {
            lowestStudents.push_back(student);
        }
    }

    cout << "Danh sach hoc sinh co diem toan thap nhat (" << fixed << setprecision(2) << minMathScore << "):\n";
    for (const auto &student : lowestStudents) {
        cout << student.name << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    int n;
    cout << "Nhap so luong hoc sinh: " << flush;
    cin >> n;
    if(cin.fail() || n <= 0){
        cout << "So luong hoc sinh khong hop le!\n";
        return 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    vector<Student> students;
    inputStudents(students, n);

    cout << "\nThong tin hoc sinh\n";
    for (const auto &student : students) {
        cout << student.name << " - Diem trung binh: " 
             << fixed << setprecision(2) << student.averageScore 
             << " (Phan loai: " << student.classification << ")" << '\n';
    }

    findTopStudent(students);
    searchStudent(students);
    findLowestMathScore(students);
    
    exit(0);
    }
