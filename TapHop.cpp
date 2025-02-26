#include <bits/stdc++.h>
#define CLEAR() system("cls")
using namespace std;

class TH{
private:
    vector<int> arr;
public:

    //! Thiết lập constructor mặc định
    TH(){}

    //! Nhập dữ liệu đầu vào
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

    //! Xuất dữ liệu ra màn hình
    friend ostream &operator<<(ostream &os, const TH &b){
        os << "{";
        for (size_t i = 0; i < b.arr.size(); i++){
            os << b.arr[i];
            if (i < b.arr.size() - 1){
                os << ", ";
            }
        }
        os << "}";
        os << endl;
        return os;
    }

    //! Hợp hai tập hợp
    TH operator+(TH &b){
        TH res;
        res.arr = arr;
        res.arr.insert(res.arr.end(), b.arr.begin(), b.arr.end());

        sort(res.arr.begin(), res.arr.end());

        auto last = unique(res.arr.begin(), res.arr.end());
        res.arr.erase(last, res.arr.end());

        return res;
    }


    //! Hiệu hai tập hợp
    TH operator-(TH &b){
        TH res;
        for (auto& s : arr){
            if (find(b.arr.begin(), b.arr.end(), s) == b.arr.end()){
                res.arr.push_back(s);
            }
        }
        return res;
    }

    //! Giao hai tập hợp
    TH operator*(const TH &b){
        TH res;
        for (const auto& s : arr){
            if (find(b.arr.begin(), b.arr.end(), s) != b.arr.end()){
                res.arr.push_back(s);
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

    cout << "Tap hop tong: " << (c = a + b);
    cout << "Tap hop nhan: " << (c = a * b);
    cout << "Tap hop tru(A - B): " << (c = a - b);
    cout << "Tap hop tru(B - A): " << (c = b - a);
    return 0;
}
