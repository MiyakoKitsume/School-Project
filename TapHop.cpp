#include <bits/stdc++.h>
#define CLEAR() system("cls")
using namespace std;

class TH{
private:
    vector<int> arr;
public:
    friend istream &operator>>(istream &is, TH &b){
        int n;
        cout << "\nNhap so luong phan tu trong tap hop: ";
        is >> n;
        cout << "Nhap cac phan tu tap hop: ";
        b.arr.resize(n);
        for (int i = 0; i < n; i++){
            is >> b.arr[i];
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, const TH &b){
        for (int i = 0; i < b.arr.size(); i++){
            os << b.arr[i] << " ";
        }
        os << endl;
        return os;
    }

    TH operator+(const TH &b){
        TH res;
        res.arr = arr;
        res.arr.insert(res.arr.end(), b.arr.begin(), b.arr.end());

        sort(res.arr.begin(), res.arr.end());

        auto last = unique(res.arr.begin(), res.arr.end());
        res.arr.erase(last, res.arr.end());

        return res;
    }

    TH operator-(const TH &b){
        TH res;
        for (int i = 0; i < arr.size(); i++) {
            bool found = false;
            for (int j = 0; j < b.arr.size(); j++) {
                if (arr[i] == b.arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                res.arr.push_back(arr[i]);
            }
        }
        return res;
    }

    TH operator*(const TH &b){
        TH res;
        for (int i = 0; i < arr.size(); i++) {
            bool found = false;
            for (int j = 0; j < b.arr.size(); j++) {
                if (arr[i] == b.arr[j]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                res.arr.push_back(arr[i]);
            }
        }
        return res;
    }
};

int main(){
    CLEAR();
    TH a, b, c;
    cout << "Nhap tap hop a: "; cin >> a;
    cout << "Nhap tap hop b: "; cin >> b;

    cout << "Tap hop tong: ";
    c = a + b;
    cout << c;

    cout << "Tap hop nhan: ";
    c = a * b;
    cout << c;

    cout << "Tap hop tru(A - B): ";
    c = a - b;
    cout << c;

    cout << "Tap hop tru(B - A): ";
    c = b - a;
    cout << c;

    return 0;
}
