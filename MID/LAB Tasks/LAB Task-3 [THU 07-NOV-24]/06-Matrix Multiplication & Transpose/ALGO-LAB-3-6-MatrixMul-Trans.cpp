//ALGO-LAB-3-6-MatrixMul-Trans

#include <iostream>
#include <conio.h>
using namespace std;

const int row = 3;
const int col = 4;

void InputMatrix(int matrix[row][col], int num) {

    cout << endl << "Enter elements for Matrix " << num << " (" << row << "x" << col << "):" << endl;
    for(int i=0; i<row; i++) {

        for(int j=0; j<col; j++) {
            cin >> matrix[i][j];
        }

    }

}

void MultiplyMatrix(int matrix1[row][col], int matrix2[row][col], int result[row][col]) {

    for(int i=0; i<row; i++) {

        for(int j=0; j<col; j++) {

            result[i][j] = 0;
            for(int k=0; k<row; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }

        }

    }

}

void TransposeMatrix(int matrix[row][col], int transpose[col][row]) {

    for(int i=0; i<row; i++) {

        for(int j=0; j<col; j++) {
            transpose[j][i] = matrix[i][j];
        }

    }

}

void ShowMatrix(int matrix[row][col]) {

    for(int i=0; i<row; i++) {

        for(int j=0; j<col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;

    }
}

void ShowTransposeMatrix(int matrix[col][row]) {

    for(int i=0; i<col; i++) {

        for (int j=0; j<row; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;

    }

}

int main() {
    int matrix1[row][col], matrix2[row][col], matrix3[row][col], matrix4[row][col];
    int temp1[row][col], temp2[row][col], result[row][col];
    int transpose[col][row];

    InputMatrix(matrix1, 1);
    InputMatrix(matrix2, 2);
    InputMatrix(matrix3, 3);
    InputMatrix(matrix4, 4);

    MultiplyMatrix(matrix1, matrix2, temp1);
    MultiplyMatrix(temp1, matrix3, temp2);
    MultiplyMatrix(temp2, matrix4, result);

    TransposeMatrix(result, transpose);

    cout << endl << "Matrix after multiplication:" << endl;
    ShowMatrix(result);

    cout << endl << "Transpose of the output matrix:" << endl;
    ShowTransposeMatrix(transpose);

    cout << endl << "Press any key to close...";
    getch();
    cout << endl;

    return 0;
}
