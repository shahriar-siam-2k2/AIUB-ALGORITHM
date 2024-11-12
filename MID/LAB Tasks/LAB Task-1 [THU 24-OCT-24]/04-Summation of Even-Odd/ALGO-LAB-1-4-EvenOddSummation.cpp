//ALGO-LAB-1-4: Write a program to find/determine odd/even numbers in a given array and calculate the the summation of odd/even numbers.

#include <iostream>
#include <conio.h>
using namespace std;

bool isEven(int n) {
    if(n % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int size, evenSum=0, oddSum=0;

    cout << endl << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " integer numbers: ";
    for(int i=0 ; i<size ; i++) {
        cin >> arr[i];
        if(isEven(arr[i])) {
            evenSum += arr[i];
        }
        else {
            oddSum += arr[i];
        }
    }

    cout << endl << "Summation of Even numbers: " << evenSum;
    cout << endl << "Summation of Odd numbers: " << oddSum << endl;

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}