//ALGO-LAB-1-7: Write a program to calculate the factorial value of a number.

#include <iostream>
#include <conio.h>
using namespace std;

int factorialDetermine(int n) {
    int factorial = 1;
    for(int i=n ; i > 0 ; i--) {
        factorial = factorial*i;
    }
    return factorial;
}

int main() {
    int number;

    cout << endl << "Enter Integer number: ";
    cin >> number;

    cout << endl << "Factorial of " << number << " is: " << factorialDetermine(number);

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}