//ALGO-LAB-1-8: write a program to check palindrome numbers.

#include <iostream>
#include <conio.h>
using namespace std;

bool isPalindrome(int num) {
    int testNum = num, reversedNum=0, rem;

    while(testNum != 0) {
        rem = testNum % 10;
        reversedNum = (reversedNum * 10) + rem;
        testNum /= 10;
    }

    if(reversedNum == num) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int num;

    cout << endl << "Enter inteager number: ";
    cin >> num;

    if(isPalindrome(num)) {
        cout << endl << num << " is a palindrome number.";
    }
    else {
        cout << endl << num << " is not a palindrome number.";
    }

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}