// ALGO-FINAL-LT-9-3-Similarity

#include <iostream>
using namespace std;

int LCS_len(string word1, string word2) {
    int w1Len, w2Len;
    string lcs = "";

    w1Len = word1.length();
    w2Len = word2.length();

    int** lcsArr = new int* [w1Len+1];
    for(int i=0; i<=w1Len; i++) {
        lcsArr[i] = new int [w2Len+1];
    }

    for(int i=0; i<=w1Len; i++) {
        for(int j=0; j<=w2Len; j++) {
            lcsArr[i][j] = 0;
        }
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

    int i = w1Len;
    int j = w2Len;

    while (i > 0 && j > 0) {

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

    return lcs.length();
}


int main() {
    int aus_aust, aus_arg;

    string aust = "Austria";
    string arg = "Argentina";
    string aus = "Australia";

    aus_aust = LCS_len(aus, aust);
    aus_arg = LCS_len(aus, arg);

    if(aus_aust > aus_arg) {
        cout << endl << aust << " is more similar to " << aus << " than " << arg << "." << endl;
    }
    else if(aus_aust < aus_arg) {
        cout << endl << arg << " is more similar to " << aus << " than " << aust << "." << endl;
    }
    else {
        cout << endl << aust << " and " << arg << " are equaly similar to " << aus << "." << endl;
    }

    return 0;
}