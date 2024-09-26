#include <iostream>

using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:
    string Company;
    int Age;
protected:
    string Name;
public:
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    
    void setName(int age) {
        Age = age;
    }
    int getAge() {
        return Age;
    }
    
    void Introducing() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion() {
        if (Age > 30)
            cout << Name << " got promoted" << endl;
        else 
            cout << Name << " didn't got promoted" << endl;
        
    }
    virtual void Work() {
        cout << Name << " is checking email, task backlog, performing tasks" << endl;
    }
};

class Developer:public Employee {
public:
    string ProgrammingLanguage;
    Developer(string name, string company, int age, string language)
        :Employee(name, company, age)
    {
        ProgrammingLanguage = language;
    }
    void FixBug() {
        cout << Name << " fixxed bug using " << ProgrammingLanguage << endl;
    }
    void Work() {
        cout << Name << " is coding on " << ProgrammingLanguage << endl;
    }
};

class Musician:public Employee {
public:    
    string Music;
    void MakingMusic() {
        cout << Name << " is making music named: " << Music << endl;
    }
    void Work() {
        cout << Name << " is working on " << Music << endl;
    }
    Musician(string name, string company, int age, string music)
        :Employee(name, company, age)
    {
        Music = music;   
    }
}; 

int main() {
    //Employee employee1 = Employee("Garfield", "Apple", 45);
    //employee1.Introducing();
    //employee1.AskForPromotion();
    //cout << "\n"<< endl;
    //Employee employee2 = Employee("John", "Microsoft", 25);
    //employee2.Introducing();
    //employee2.AskForPromotion();

    Developer a = Developer("Garfield", "Apple", 45, "Python");
    //a.FixBug();
    //a.AskForPromotion();

    Musician b = Musician("Jack", "J97 Entertainment", 5000000, "Thien Ly oi");
    //b.MakingMusic();
    Employee* e1 = &a;
    Employee* e2 = &b;

    e1->Work();
    e2->Work();

    return 0;
}