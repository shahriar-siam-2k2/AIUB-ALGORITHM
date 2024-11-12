//ALGO-LAB-2-6: Leap years between two years.

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
    int fromYear, toYear;
    bool found = false;

    cout << endl << "Enter starting year: ";
    cin >> fromYear;
    cout << "Enter ending year: ";
    cin >> toYear;

    for(int i=fromYear; i<=toYear; i++) {
        if(isLeapYear(i)) {
            if(!found) {
                cout << endl << "Leap years between " << fromYear << " to " << toYear << ":" << endl;
                found = true;
            }
            cout << i << endl;
        }
    }

    if(!found) {
        cout << endl << "No leap years between " << fromYear << " to " << toYear << "!" << endl;
    }

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}