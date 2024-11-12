//ALGO-LAB-1-3: Write a programm to find/determine prime number.

#include <iostream>
#include <conio.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }

    for(int i=2 ; i*i <= n ; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;

    cout << endl << "Enter any integer number: ";
    cin >> n;

    if(isPrime(n)) {
        cout << endl << n << " is a prime number." << endl;
    }
    else {
        cout << endl << n << " is not a prime number." << endl;
    }

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}