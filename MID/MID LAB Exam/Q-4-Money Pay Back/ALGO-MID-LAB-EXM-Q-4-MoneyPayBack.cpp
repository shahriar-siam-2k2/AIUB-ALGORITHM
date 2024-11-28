//ALGO-MID-LAB-EXM-Q-4-MoneyPayBack

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int money = 3987;
    int notes[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2};
    int notesCount[9] = {0};
    int amount = money;

    for(int i = 0; i < 9; i++) {

        if(amount >= notes[i]) {

            notesCount[i] = amount / notes[i];
            amount %= notes[i];

        }

    }

    cout << endl << "To pay " << money << " taka, you need the following notes:" << endl;
    for(int i = 0; i < 9; i++) {

        if(notesCount[i] > 0) {

            cout << notes[i] << " Taka: " << notesCount[i];

            if(notesCount[i] > 1) {
                cout << " notes" << endl;
            }
            else {
                cout << " note" << endl;
            }

        }

    }

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}