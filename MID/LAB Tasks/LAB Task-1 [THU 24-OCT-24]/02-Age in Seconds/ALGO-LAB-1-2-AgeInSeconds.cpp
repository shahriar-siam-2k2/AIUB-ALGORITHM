//ALGO-LAB-1-2: Write a program to calculte your age in seconds.

#include <iostream>
#include <conio.h>
using namespace std;

bool isLeapYear(int year) {
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int day, month, year, totalDays=0, leapYearCount=0, currentYear=2024;
    long long int ageInSeconds;

    cout << endl << "Enter your birth day (dd): ";
    cin >> day;
    cout << "Enter your birth month in number (mm): ";
    cin >> month;
    cout << "Enter your birth year (yyyy): ";
    cin >> year;

    for(int i=year ; i<currentYear ; i++) {
        if(isLeapYear(i)) {
            leapYearCount++;
        }
    }

    totalDays = (((currentYear - year) * 365) + leapYearCount) + (month * 30) + day;
    ageInSeconds = totalDays * 24 * 3600;

    cout << endl << "Your age in seconds is: " << ageInSeconds << " s." << endl;

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}