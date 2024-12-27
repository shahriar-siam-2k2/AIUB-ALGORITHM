// ALGO-FINAL-LT-9-4-MCM

#include <iostream>
using namespace std;

void MCM(int d[], int n) {
    int **M = new int *[n];
    for(int i=0; i<n; i++) {
        M[i] = new int [n];
    }

    int **S = new int *[n];
    for(int i=0; i<n; i++) {
        S[i] = new int [n];
    }

    for(int i=1; i<n; i++) {

        for(int j=1; j<n; j++) {

            if (i == j) {
                M[i][j] = 0;
            }
            S[i][j] = 0;

        }
    }

    for(int len=2; len<n; len++) {

        for(int i=1; i<=n-len ; i++) {

            int j = i + len - 1;
            M[i][j] = 2147483647;

            for(int k=i; k<=j-1; k++) {

                int q = M[i][k] + M[k+1][j] + d[i-1] * d[k] * d[j];

                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }

            }

        }

    }

    cout << endl << "Minimum number of scalar multiplications: " << M[1][n-1] << endl;

    cout << endl << "S matrix:" << endl;
    for(int i=1; i<n; i++) {

        for(int j=1; j<n; j++) {

            if(i <= j) {
                cout << S[i][j] << " ";
            }
            else {
                cout << "  ";
            }

        }
        cout << endl;

    }

    for(int i=0; i<n; i++) {
        delete[] M[i];
    }
    delete[] M;

    for(int i=0; i<n; i++) {
        delete[] S[i];
    }
    delete[] S;
}

int main() {
    int matrices;
    cout << endl << "Enter the number of matrices: ";
    cin >> matrices;

    int *dimensions = new int [matrices+1];

    cout << endl;
    for(int i=0; i<matrices; i++) {
        cout << "Enter matrix-" << i+1 << " dimension (a x b): ";
        if(i == 0) {
            cin >> dimensions[i] >> dimensions[i+1];
        }
        else {
            int temp;
            cin >> temp >> dimensions[i+1];

            if (temp != dimensions[i]) {
                cout << endl << "\tDimensions not matched for matrix multiplication!" << endl;
                return 0;
            }
        }
    }

    MCM(dimensions, matrices+1);

    delete[] dimensions;
    return 0;
}