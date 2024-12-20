// ALGO-FINAL-LT-8-1-LcsAlgo

#include <iostream>
using namespace std;

string LCS(string word1, string word2) {
    int w1Len, w2Len;
    string lcs = "";

    w1Len = word1.length();
    w2Len = word2.length();

    int** lcsArr = new int* [w1Len+1];
    for(int i=0; i<=w1Len; i++) {
        lcsArr[i] = new int [w2Len+1];
    }

    cout << endl << "Initialize table-" << endl;
    for(int i=0; i<=w1Len; i++) {
        for(int j=0; j<=w2Len; j++) {
            lcsArr[i][j] = 0;
            cout << lcsArr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=1; i<=w1Len; i++) {
        for(int j=1; j<=w2Len; j++) {
            
            if(word1[i-1] == word2[j-1]) {
                lcsArr[i][j] = lcsArr[i-1][j-1] + 1;
            }
            else if(lcsArr[i-1][j] > lcsArr[i][j-1]) {
                lcsArr[i][j] = lcsArr[i-1][j];
            }
            else {
                lcsArr[i][j] = lcsArr[i][j-1];
            }

        }
    }

    cout << endl << "After finding-" << endl;
    for(int i=0; i<=w1Len; i++) {
        for(int j=0; j<=w2Len; j++) {
            cout << lcsArr[i][j] << " ";
        }
        cout << endl;
    }

    int i = w1Len;
    int j = w2Len;

    cout << endl << "Paths in the table-" << endl;
    while (i > 0 && j > 0) {

        for (int row = 0; row <= w1Len; row++) {
            for (int col = 0; col <= w2Len; col++) {

                if (row == i && col == j) {
                    if(word1[i - 1] == word2[j - 1]) {
                        cout << "(corner)<-" << lcsArr[row][col] << " ";
                    }
                    else if(lcsArr[row - 1][col] > lcsArr[row][col - 1]) {
                        cout << "(up)<-" << lcsArr[row][col] << " ";
                    }
                    else {
                        cout << "(left)<-" << lcsArr[row][col] << " ";
                    }
                }
                else {
                    cout << lcsArr[row][col] << " ";
                }

            }
            cout << endl;
        }
        cout << endl;

        if(word1[i - 1] == word2[j - 1]) {
            lcs = word1[i - 1] + lcs;
            i--;
            j--;
        }
        else if(lcsArr[i - 1][j] > lcsArr[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }

    }

    for(int i=0; i<=w1Len; i++) {
        delete[] lcsArr[i];
    }
    delete[] lcsArr;

    return lcs;
}


int main() {
    string word1, word2, lcs;

    cout << endl << "Enter word-1: ";
    cin >> word1;
    cout << "Enter word-2: ";
    cin >> word2;

    lcs = LCS(word1, word2);

    cout << endl << "Similarity of above two words are: " << lcs << endl;
    cout << "Length of the similarity: " << lcs.length() << endl;

    return 0;
}