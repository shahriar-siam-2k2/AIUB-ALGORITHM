// ALGO-FINAL-LT-8-1-LcsAlgo

#include <iostream>
using namespace std;

string LCS(string word1, string word2) {
    int w1Len, w2Len;
    string lcs = "";

    w1Len = word1.length();
    w2Len = word2.length();

    int lcsArr[w1Len+1][w2Len+1];

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

        // Corrected table initialization and LCS calculation
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

    cout << endl << "Paths in the table-" << endl;
    int i = w1Len, j = w2Len;
    while(i > 0 && j > 0) {
        cout << lcsArr[i][j] << " ";
        if(word1[i-1] == word2[j-1]) {
            lcs = word1[i-1] + lcs;
            cout << "corner-" << lcsArr[i][j] << " ";
            i--;
            j--;
        } 
        else if(lcsArr[i-1][j] > lcsArr[i][j-1]) {
            cout << "up-" << lcsArr[i][j] << " ";
            i--;
        } 
        else {
            cout << "left-" << lcsArr[i][j] << " ";
            j--;
        }
    }

    cout << endl;



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