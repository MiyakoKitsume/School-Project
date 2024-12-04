#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <conio.h>

#define KEY_RIGHT 77
#define KEY_LEFT 75
#define CLEAR_SCREEN() system("cls")

using namespace std;

struct Student {
    int stt;
    string hoTen;
    float toan, ly, hoa;
    float diemTB;
};

void inputStudentData(Student& s, int stt) {
    s.stt = stt;
    cout << "+ Ho va Ten: ";
    do {
        getline(cin, s.hoTen);
    } while (s.hoTen.size() == 0);
    cout << "+ Diem Toan: ";
    cin >> s.toan;
    
    cout << "+ Diem Ly: ";
    cin >> s.ly;
    
    cout << "+ Diem Hoa: ";
    cin >> s.hoa;
    s.diemTB = round(((s.toan + s.ly + s.hoa) / 3.0) * 100.0) / 100.0;
}

bool readStudentData(ifstream& fi, Student& s, int stt) {
    if (!getline(fi, s.hoTen) || !(fi >> s.toan >> s.ly >> s.hoa)) {
        return false;
    }
    fi.ignore();
    s.stt = stt;
    s.diemTB = round(((s.toan + s.ly + s.hoa) / 3.0) * 100.0) / 100.0;
    return true;
}

void writeStudentData(ofstream& fo, const Student& s) {
    fo << s.hoTen << endl;
    fo << s.toan << endl;
    fo << s.ly << endl;
    fo << s.hoa << endl;
}

void displayStudent(const Student& s) {
    cout << "|" << setw(4) << s.stt << " | " << setw(20) << right << s.hoTen
         << " |" << setw(5) << s.toan
         << " |" << setw(3) << s.ly
         << " |" << setw(4) << s.hoa
         << " |" << setw(8) << s.diemTB << " |" << endl;
}

void displayHeader() {
    cout << "----------------------------------------------------------" << endl;
    cout << "| STT |       Ho Ten        | Toan | Ly  | Hoa | Diem TB |" << endl;
    cout << "----------------------------------------------------------" << endl;
}

bool compareStudents(const Student& a, const Student& b, int sortChoice) {
    switch (sortChoice) {
        case 1: return a.hoTen < b.hoTen;
        case 2: return a.hoTen > b.hoTen;
        case 3: return a.diemTB < b.diemTB;
        case 4: return a.diemTB > b.diemTB;
        default: return false;
    }
}

void readFileData(const string& filename, vector<Student>& students) {
    ifstream fi(filename);
    if (!fi.is_open()) {
        cout << "Khong the mo file: " << filename << endl;
        return;
    }
    int n;
    fi >> n;
    fi.ignore();
    students.clear();
    for (int i = 0; i < n; ++i) {
        Student s;
        if (readStudentData(fi, s, i + 1))
            students.push_back(s);
        else {
            cout << "Loi doc du lieu tu file tai dong thu " << i + 1 << endl;
            break;
        }
    }
    fi.close();
}

void writeFileData(const string& filename, const vector<Student>& students) {
    ofstream fo(filename);
    if (!fo.is_open()) {
        cout << "Khong the mo file de ghi: " << filename << endl;
        return;
    }
    fo << students.size() << endl;
    for (const auto& student : students) {
        writeStudentData(fo, student);
    }
    fo.close();
}

void displayPaginated(const vector<Student>& students, int entriesPerPage) {
    int currentPage = 0;
    int totalPages = (students.size() + entriesPerPage - 1) / entriesPerPage;

    do {
        CLEAR_SCREEN();
        displayHeader();
        for (int i = currentPage * entriesPerPage;
             i < min((currentPage + 1) * entriesPerPage, (int)students.size()); ++i) {
            displayStudent(students[i]);
        }
        cout << "----------------------------------------------------------" << endl;
        cout << "Tuy chon:" << endl;
        cout << "- An nut <- va -> de chuyen trang" << endl;
        cout << "- An so 0 de quay lai" << endl;
        int key = getch();
        if (key == 0 || key == 224) {
            key = getch();
            if (key == KEY_LEFT && currentPage > 0) {
                currentPage--;
            } else if (key == KEY_RIGHT && currentPage < totalPages - 1) {
                currentPage++;
            }
        } else if (key == '0') {
            break;
        }
    } while (true);
}

void addStudent(const string& filename, vector<Student>& students){
    int n;
    cout << "Nhap so luong hoc sinh can them: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    readFileData(filename, students);

    for (int i = 0; i < n; i++) {
        Student newStudent;
        cout << "Nhap thong tin sinh vien thu " << students.size() + 1 << ":" << endl;
        inputStudentData(newStudent, students.size() + 1);
        students.push_back(newStudent);
    }
    writeFileData(filename, students);
}

void searchStudent(vector<Student>& students) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string name;
    cout << "Nhap ten can tim: ";
    getline(cin, name);

    bool foundName = false;
    displayHeader();

    for (const auto& s : students) {
        const string& studentName = s.hoTen;
        if (studentName.size() == name.size()) {
            bool isMatch = true;
            for (size_t i = 0; i < studentName.size(); i++) {
                if (tolower(studentName[i]) != tolower(name[i])) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                displayStudent(s);
                foundName = true;
            }
        }
    }

    if (!foundName) {
        cout << "Khong tim thay sinh vien nao voi ten \"" << name << "\"." << endl;
    } else {
        cout << "----------------------------------------------------------" << endl;
    }

    cout << "Nhan phim bat ky de quay lai menu....." << endl;
    getch();
}


void deleteStudent(const string& filename, vector<Student> students){
    int stt;
    cout << "Nhap STT sinh vien can xoa: ";
    cin >> stt;
    students.erase(students.begin() + (stt - 1));
    for (size_t i = 0; i < students.size(); ++i) {
        students[i].stt = i + 1;
    }
    cout << "Xoa thanh cong!" << endl;
    writeFileData(filename, students);
}

void editStudent(const string& filename, vector<Student> students){
    int stt;
    cout << "Nhap STT ( gom " << students.size() + 1 << " stt) sinh vien can chinh sua: ";
    cin >> stt;
    for (auto& s : students) {
        if (s.stt == stt) {
            inputStudentData(s, stt);
            break;
        } else {
            cout << "Khong tim thay stt";
            break;
        }
    }
    writeFileData(filename, students);
}

void sortStudent(const string& filename, vector<Student> students){
    int sortChoice;
    cout << "Sap xep theo:" << endl;
    cout << "1. Ho Ten tang dan" << endl;
    cout << "2. Ho Ten giam dan" << endl;
    cout << "3. Diem TB tang dan" << endl;
    cout << "4. Diem TB giam dan" << endl;
    cout << "0. Thoat" << endl;
    cin >> sortChoice;
    if (sortChoice != 0) {
        sort(students.begin(), students.end(), [&](const Student& a, const Student& b) {
            return compareStudents(a, b, sortChoice);
        });
        displayHeader();
        for (const auto& student : students) {
            displayStudent(student);
        }
        writeFileData(filename, students);
    }
}

void mainMenu(){
    vector<Student> students;
    const string filename = "C:\\Users\\Kitsume\\Documents\\Data.txt";
    int choice;
    CLEAR_SCREEN();
    do {
        cout << "Menu: " << endl;
        cout << "1. Hien thi danh sach" << endl;
        cout << "2. Them moi" << endl;
        cout << "3. Sap xep" << endl;
        cout << "4. Tim kiem" << endl;
        cout << "5. Chinh sua" << endl;
        cout << "6. Xoa" << endl;
        cout << "0. Thoat" << endl;
        cin >> choice;
        CLEAR_SCREEN();
        switch (choice) {
            case 1:
                CLEAR_SCREEN();
                readFileData(filename, students);
                if (students.empty()) {
                    cout << "Danh sach sinh vien trong!" << endl;
                } else {
                    displayPaginated(students, 8);
                }
                break;
            case 2:
                CLEAR_SCREEN();
                addStudent(filename, students);
                break;

            case 3:
                CLEAR_SCREEN();
                sortStudent(filename, students);
                break;
            case 4: {
                CLEAR_SCREEN();
                searchStudent(students);
                break;
            }
            case 5:
                CLEAR_SCREEN();
                editStudent(filename, students);
                break;
            case 6:
                CLEAR_SCREEN();
                deleteStudent(filename, students);
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
        CLEAR_SCREEN();
    } while (choice != 0);
}

int main() {
    mainMenu();    
    return 0;
}
