#include <bits/stdc++.h>
#define CLEAR() system("cls")
using namespace std;

class DS{
private:
    //! Setup varible in private
    int *a;
    int n;
public:

    //! Set a new random binary array
    void getNewArray(int n){
        this->n = n;
        a = new int[n];
        srand(time(NULL));

        for (int i = 0; i < n; i++){
            a[i] =  rand() % 101;
        }
    }

    //! Calling destructor
    ~DS(){ cout << "\n\t------Destructor called...\n"; delete[] a;}

    //! Output class set in main() fuction
    void output(){
        cout << "Amount of numbers in array: " << n << endl;
        cout << "Content of the row of numbers: ";
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }

        cout << endl;
    }

    //! Increasing k number in subset array
    void increaseNumber(int k){
        for (int i = 0; i < n; i++){
            a[i] += k;
        }
    }

    //! Creating base function copying class to another class in main() fuction
    DS(const DS& b){
        cout << "\n\t------Copy called...\n";
        n = b.n;
        a = new int[n];
        for (int i = 0; i < n; i++){
            a[i] = b.a[i];
        }
    }

    //! Creating equal operator creating another copy of class
    DS operator=(DS& b){
        delete[] a;
        n = b.n;
        a = new int[n];
        for (int i = 0; i < n; i++){
            a[i] = b.a[i];
        }
        return *this;
    }

    //! Calling contructor
    DS(){ cout << "\n\t------Constructor called...\n";n = 0; a = NULL;}
};

int main(){
    CLEAR();
    DS a; a.getNewArray(10); a.output();
    DS c(a); // !Copy varible from original class to a new class
    c.output(); a.increaseNumber(10); a.output(); c.output();
    
    DS b; b=a; b.output();
    cout << "Succed!!\n";
    return 0;
}
