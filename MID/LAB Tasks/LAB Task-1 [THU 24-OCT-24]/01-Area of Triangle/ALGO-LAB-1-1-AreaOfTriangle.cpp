//ALGO-LAB-1-1: Write a program to calculate the area of a triangle with base and height.

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    double base, height, area;

    cout << endl << "Enter the base of triangle: ";
    cin >> base;
    cout << "Enter the height of triangle: ";
    cin >> height;

    area = 0.5 * base * height;

    cout << endl << "The area of the triangle is " << area << " Units." << endl;

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}