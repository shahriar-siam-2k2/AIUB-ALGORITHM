//ALGO-LAB-1-5: 

#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main() {
    float rate = 6.5;
    double initialBalance = 100000, monthlyIntRate = rate / 100;
    double finalBalance = initialBalance;
    int year = 6;
    int totalMonths = year * 12;

    for(int i=0 ; i < totalMonths ; i++) {
        finalBalance += finalBalance * monthlyIntRate;
    }

    cout << fixed << setprecision(2);
    cout << endl << "Initial Balance: " << initialBalance;
    cout << endl << "Final Balance: " << finalBalance << endl;

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}