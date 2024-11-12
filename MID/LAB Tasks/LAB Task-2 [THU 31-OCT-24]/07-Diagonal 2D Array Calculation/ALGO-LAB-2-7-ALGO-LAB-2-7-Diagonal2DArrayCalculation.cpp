//ALGO-LAB-2-7: Diagonal 2D Array Calculation.

#include <iostream>
#include <conio.h>
using namespace std;

void diagonalCalc(double arr[][100], int n, char diagonal) {
    double sum = 0;

    for(int i = 0; i < n; i++) {
        if(diagonal == '1') {
            sum += arr[i][i];
        }
        else {
            sum += arr[i][n - i - 1];
        }
    }

    double average = sum / n;

    cout << endl << "Sum of diagonal-" << diagonal << ": " << sum << endl;
    cout << "Average of diagonal-" << diagonal << ": " << average << endl;
}

int main() {
    int n;

    cout << endl << "Enter the size of the square matrix (n x n): ";
    cin >> n;

    double arr[100][100];

    cout << endl << "Enter the elements of the matrix:" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    diagonalCalc(arr, n, '1');
    diagonalCalc(arr, n, '2');

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}