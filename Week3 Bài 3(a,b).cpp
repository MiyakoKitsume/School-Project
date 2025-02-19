#include <bits/stdc++.h>
using namespace std;
class Movie{
private:
    string Title;
    int Year;
    string Director;

    void setTitle(string title){
        title = Title;
    }

    void setYear(int year){
        year = Year;
    }

    void setDirector(string director){
        director = Director;
    }
public:
    Movie(string title, int year, string director){
        setTitle(title);
        setYear(year);
        setDirector(director);
    }

    Movie(){}

    void input(){
        cout << "Insert a name of the movie: "; cin.ignore();
        getline(cin, Title);
        cout << "Input year of release of the movie: ";
        cin >> Year;
        cout << "Input name of the movie director: "; cin.ignore();
        getline(cin, Director);
    }

    void output(){
        cout << "Title: " << Title << endl;
        cout << "Year: " << Year << endl;
        cout << "Director: " << Director << endl;
    }

    void compareMovie(Movie& mv){
        if (Year == mv.Year) cout << "Both movies are release in the same year!" << endl;
        else cout << "Both movies are release in the different year!" << endl;

        if (Director == mv.Director) cout << "Both movies are have the same director!" << endl;
        else cout << "Both movies are have the different director!" << endl;
    }
};
int main(){
    Movie mv1, mv2;

    cout << "Input movie #1: " << endl;
    mv1.input();
    cout << "Input movie #2: " << endl;
    mv2.input();

    cout << "Movie #1: " << endl;
    mv1.output();
    cout << "Movie #2: " << endl;
    mv2.output();

    cout << "Comparison: " << endl;
    mv1.compareMovie(mv2);
    return 0;
}
