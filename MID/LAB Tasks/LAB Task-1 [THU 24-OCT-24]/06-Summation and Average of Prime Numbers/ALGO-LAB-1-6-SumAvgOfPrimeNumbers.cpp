//ALGO-LAB-1-6: Write a program to calculate the summation and average value of prime numbers between range of 100.

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
    int sum=0, primeCount=0;
    float avg;

    for(int i=0 ; i<=100 ; i++) {
        if(isPrime(i)) {
            sum += i;
            primeCount++;
        }
    }

    avg = sum / (float)primeCount;

    cout << endl << "Summation of prime numbers between range of 100 is: " << sum;
    cout << endl << "Average of prime numbers between range of 100 is: " << avg;

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}