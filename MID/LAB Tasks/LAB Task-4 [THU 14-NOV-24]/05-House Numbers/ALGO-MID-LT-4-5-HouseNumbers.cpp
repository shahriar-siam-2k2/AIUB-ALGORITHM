//ALGO-MID-LT-4-5-HouseNumbers

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int n = 20;
    int first = 0, second = 1, next;

    cout << endl << "First 20 house numbers in the area:" << endl;

    for(int i = 0; i < n; i++) {

        cout << first << " ";

        next = first + second;
        first = second;
        second = next;

    }

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}