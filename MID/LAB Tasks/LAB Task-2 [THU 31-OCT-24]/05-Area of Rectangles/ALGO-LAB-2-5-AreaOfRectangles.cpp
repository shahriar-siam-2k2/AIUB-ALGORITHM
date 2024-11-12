//ALGO-LAB-2-5: Area of Rectangles

#include <iostream>
#include <conio.h>
using namespace std;

double areaOfRectangle() {
    double length, width;
    
    cout << endl << "Enter rectangle length: ";
    cin >> length;
    cout << "Enter rectangle width: ";
    cin >> width;
    
    return length * width;
}

double areaOfSquare() {
    double side;
    
    cout << endl << "Enter square side: ";
    cin >> side;
    
    return side * side;
}

double areaOfRhombus() {
    double diagonal1, diagonal2;
    
    cout << endl << "Enter rhombus diagonal 1: ";
    cin >> diagonal1;
    cout << "Enter rhombus diagonal 2: ";
    cin >> diagonal2;
    
    return 0.5 * diagonal1 * diagonal2;
}

double areaOfParallelogram() {
    double base, height;
    
    cout << endl << "Enter parallelogram base: ";
    cin >> base;
    cout << "Enter parallelogram height: ";
    cin >> height;
    
    return base * height;
}

double areaOfTrapezoid() {
    double height, a, b;
    
    cout << endl << "Enter trapezoid first parallel side: ";
    cin >> a;
    cout << "Enter trapezoid second parallel side: ";
    cin >> b;
    cout << "Enter trapezoid heigth: ";
    cin >> height;
    
    return 0.5 * (a + b) * height;
}

int main() {
    char op;
    double area;

    while(true) {
        cout << endl << "1. Area of Rectangle" << endl
                     << "2. Area of Square" << endl
                     << "3. Area of Rhombus" << endl
                     << "4. Area of Parallelogram" << endl
                     << "5. Area of Trapezoid" << endl
                     << "6. Exit" << endl;
        cout << "Choose your option: ";
        cin >> op;

        if(op == '1') {
            area = areaOfRectangle();
            cout << endl << "Area of Rectangle: " << area << endl;
        }
        else if(op == '2') {
            area = areaOfSquare();
            cout << endl << "Area of Square: " << area << endl;
        }
        else if(op == '3') {
            area = areaOfRhombus();
            cout << endl << "Area of Rhombus: " << area << endl;
        }
        else if(op == '4') {
            area = areaOfParallelogram();
            cout << endl << "Area of Parallelogram: " << area << endl;
        }
        else if(op == '5') {
            area = areaOfTrapezoid();
            cout << endl << "Area of Trapezoid: " << area << endl;
        }
        else if(op == '6') {
            cout << endl << "Exited." << endl;
            break;
        }
        else {
            cout << endl << "INVALID INPUT!" << endl;
        }
    }
    
    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}