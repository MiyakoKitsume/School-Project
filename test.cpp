#include <iostream>
#include <cmath>
using namespace std;

double tinhKhoangCach(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int xA, yA, xB, yB;

    cout << "Nhap toa do diem A: " << endl;
    cout << "- Nhap x: ";
    cin >> xA;
    cout << "- Nhap y: ";
    cin >> yA;

    cout << "Nhap toa do diem B: " << endl;
    cout << "- Nhap x: ";
    cin >> xB;
    cout << "- Nhap y: ";
    cin >> yB;

    double distance = round(100 * tinhKhoangCach(xA, yA, xB, yB)) / 100;
    cout << "-> Khoang cach tu A(" << xA << "," << yA << ") den B(" << xB << "," << yB << ") la: " << distance << endl;

    return 0;
}
