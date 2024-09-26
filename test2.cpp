#include <iostream>
#include <string>

using namespace std;

class HoSo {
private:
    string Ten;
    string Truong;
    string MaSV;

    // Helper function to check if the string contains only digits
    bool allDigits(const string& str) {
        for (char const &c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

public:
    // Setters and Getters
    void setName(string ten) {
        Ten = ten;
    }
    string getName() {
        return Ten;
    }
    
    void setSchool(string truong) {
        Truong = truong;
    }
    string getSchool() {
        return Truong;
    }
    
    void setStuCode(string masv) {
        MaSV = masv;
    }
    string getStuCode() {
        return MaSV;
    }

    // Input method for student details
    void InputDetail() {
        cout << "Nhap ho va ten sinh vien: ";
        cin.ignore();  // Ensure any leftover input is ignored
        getline(cin, Ten);

        cout << "Nhap ten truong: ";
        getline(cin, Truong);

        do {
            cout << "Nhap ma sinh vien (11 chu so): ";
            cin >> MaSV;

            // Check if MaSV is 11 characters long and contains only digits
            if (MaSV.length() != 11 || !allDigits(MaSV)) {
                cout << "\nVui long nhap dung ma SV (11 chu so)\n";
                MaSV.clear();  // Clear invalid MaSV
            } else {
                break;  // Valid MaSV, exit the loop
            }
        } while (true);
    }

    // Method to introduce the student
    void IntroduceStudent() {
        cout << "\nSinh vien: " << Ten << endl;
        cout << "Hien dang hoc tai: " << Truong << endl;
        cout << "Ma so sinh vien: " << MaSV << endl;
    }
};

int main() {
    HoSo student;
    student.InputDetail();
    student.IntroduceStudent();
    
    return 0;
}