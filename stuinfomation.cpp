#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

class HoSo {
private:
    string Ten;
    string Truong;
    string MaSV;
    bool allDigits(const string& str) {
        for (char const &c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
public:
    void setName(string ten){
        Ten = ten;
    }
    string getName(){
        return Ten;
    }
    void setSchool(string truong){
        Truong = truong;
    }
    string getSchool(){
        return Truong;
    }
    void setStuCode(string masv){
        MaSV = masv;
    }
    string getStuCode(){
        return MaSV;
    }
    void InputDetail(){
        do {
            cout << "Nhap ho va ten sinh vien: ";
            cin.ignore();
            getline(cin, Ten);

            cout << "Nhap ten truong: ";
            getline(cin,Truong);

            cout << "Nhap ma sinh vien (11 chu so): ";
            cin >> MaSV;

            if (MaSV.length() != 11 || !allDigits(MaSV)){
                cout << " " << endl;
                cout << "Vui long nhap dung ma SV (11 chu so)\n";
                MaSV.clear();
            } else {
                break;
            }
        } while (true);
    }
    void IntroduceStudent(){
        cout << "\n";
        cout << "Sinh vien: " << Ten << endl;
        cout << "Hien dang hoc tai: " << Truong << endl;
        cout << "Ma so sinh vien: " << MaSV << endl;
    }

};

class Classes:public HoSo {
private:
    vector<string> Subject;
public:
    Classes(string ten, string truong, string masv)
    {
        setName(ten);
        setSchool(truong);
        setStuCode(masv);
    }

    Classes(){}

    void addSubject(const string& subject){
        Subject.push_back(subject);
    }

    void displaySubject() const {
        cout << "Khoa hoc dang hoc: ";
        for (size_t i = 0; i < Subject.size(); ++i) {
            cout << Subject[i];
            if (i != Subject.size() - 1) cout << ", ";
        }
        cout << endl;
    }

    void inputSubject() {
        string subject;
        cout << "Vui long nhap khoa hoc vao (go 'stop' de ket thuc): " << endl;

        do{
            cout << "Mon hoc: ";
            getline(cin, subject);
            if (subject == "stop" || subject == "STOP")
                break;
            if (!subject.empty()) {
                addSubject(subject);
            } else {
                cout << "Vui long nhap ten mon hoc!" << endl;
            }
        }while (true);
    }
};

int main(){
    HoSo sinhvien1;
    sinhvien1.InputDetail();
    sinhvien1.IntroduceStudent();
    Classes monhoc(sinhvien1.getName(), sinhvien1.getSchool(), sinhvien1.getStuCode());
    monhoc.inputSubject();
    monhoc.displaySubject();
    return 0;
}
