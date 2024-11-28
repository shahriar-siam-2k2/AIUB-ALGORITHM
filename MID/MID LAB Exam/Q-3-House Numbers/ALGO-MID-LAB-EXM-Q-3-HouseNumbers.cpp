//ALGO-MID-LAB-EXM-Q-3-HouseNumbers

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int n = 10;
    int houses[10] = {0};
    houses[1] = 1;

    for(int i = 2; i < n; i++) {

        for(int j = 0; j < i; j++) {
            houses[i] += houses[j];
        }

    }

    cout << endl << "First " << n << " house numbers in the area-" << endl;
    for(int i = 0; i < n; i++) {
        cout << "House-" << i+1 << ": " << houses[i] << " " << endl;
    }

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}
