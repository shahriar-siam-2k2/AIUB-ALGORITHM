//ALGO-LAB-1-10: write a program to convert celcius to farenheit and farenheit to celcius.

#include <iostream>
#include <conio.h>
using namespace std;

double CtoF(double c) {
    return ((9*c)/5) + 32;
}

double FtoC(double f) {
    return (5*(f-32)) / 9;
}

int main() {
    char op;
    double temp;

    cout << endl << "Choose Converter-" << endl
        << "1. Celcius to Farenheit." << endl
        << "2. Farenheit to Celcius." << endl;
    cout << "Choose your option: ";
    cin >> op;

    if(op == '1') {
        cout << endl << "Enter temperature (" << char(248) << "C): ";
        cin >> temp;
        cout << endl << "Farenheit result: " << CtoF(temp) << " " << char(248) << "F";
    }
    else if(op == '2') {
        cout << endl << "Enter temperature (" << char(248) << "F): ";
        cin >> temp;
        cout << endl << "Celcius result: " << FtoC(temp) << " " << char(248) << "C";
    }
    else {
        cout << endl << "INAVLID INPUT!";
    }

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}