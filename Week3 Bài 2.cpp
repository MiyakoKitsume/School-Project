#include <bits/stdc++.h>
#define CLEAR() system("cls")
using namespace std;

class Time{
private:
    int hours, minutes, seconds;
public:
    void input(){
        cout << "Input hours: ";
        cin >> hours;
        cout << "Input minutes: ";
        cin >> minutes;
        cout << "Input seconds: ";
        cin >> seconds;
    }

    void output(){
        if (seconds >= 60){
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60){
            hours += minutes % 60;
            minutes %= 60;
        }
        if (hours >= 24){
            hours %= 24;
        }
        cout << hours << "h:" << minutes << "m:" << seconds << "s" << endl;
    }

    Time operator+ (Time& b){
        Time res;
        res.hours = hours + b.hours;
        res.minutes = minutes + b.minutes;
        res.seconds = seconds + b.seconds;
        return res;
    }

    Time operator/ (Time& b){
        Time res;
        res.hours = round((hours / b.hours) * 100) / 100;
        res.minutes = round((minutes / b.minutes) * 100) / 100;
        res.seconds = round((seconds / b.seconds) * 100) / 100;
        return res;
    }

    int compareTime(Time& b){
        int time1 = hours *3600 + minutes *60 + seconds;
        int time2 = b.hours *3600 + b.minutes * 60 + b.seconds;

        if (time1 == time2) return 0;
        return (time1 > time2)? 1 : -1;
    }
};

int main(){
    CLEAR();
    Time time1, time2;

    time1.input();
    time2.input();

    cout << "Time #1: ";
    time1.output();
    cout << "Time #2: ";
    time2.output();

    cout << "Add: ";
    (time1+time2).output();
    cout << "Divine: ";
    (time1/time2).output();

    int cmp = time1.compareTime(time2);
    cout << "Compare time: " << cmp;
    return 0;
}
