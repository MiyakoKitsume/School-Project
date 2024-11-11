#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

//using ll = long long;

int n, m;
int arrA[100], arrB[100], arrC[200];

bool checkPrime(int n){
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

void inputArray(){
    cout << "Nhap mang A:" << endl;
    cout << "- Nhap n: "; cin >> n;
    cout << "- Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++){
        cin >> arrA[i];
    }
    cout << "Nhap mang B:" << endl;
    cout << "- Nhap n: "; cin >> m;
    cout << "- Nhap " << m << " phan tu: ";
    for (int i = 0; i < m; i++){
        cin >> arrB[i];
    }
}

void outputArray(){
    cout << "Mang A:" << endl;
    cout << "-> Mang gom " << n << " phan tu: ";
    for (int i = 0; i < n; i++){
        cout << arrA[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    cout << "Mang B:" << endl;
    cout << "-> Mang gom " << m << " phan tu: ";
    for (int i = 0; i < m; i++){
        cout << arrB[i];
        if (i < m - 1) cout << " ";
    }
    cout << endl;
}

int countPrime(int arr[], int nums){
    int count = 0;
    for (int i = 0; i < nums; i++){
        if (checkPrime(arr[i])){
            count++;
        }
    }
    return count;
}

void mergingArray(){
    for (int i = 0; i < n; i++){
        arrC[i] = arrA[i];
    }
    for (int i = 0; i < m; i++){
        arrC[i + n] = arrB[i];
    }
    for (int i = 0; i < m + n; i++){
        if (checkPrime(arrC[i])){
            cout << arrC[i];
            if (i < (m + n) - 1) cout << " ";
        }
    }
}

int main(){
    inputArray();
    outputArray();
    mergingArray();
    int primes = countPrime(arrC, n + m);
    cout << "Mang C:" << endl;
    cout << "-> Mang gom " << primes << " phan tu: ";
    return 0;
}
