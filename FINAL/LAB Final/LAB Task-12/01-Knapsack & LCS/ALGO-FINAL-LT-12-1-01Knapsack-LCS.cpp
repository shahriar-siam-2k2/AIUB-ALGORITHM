// ALGO-FINAL-LT-12-1-Knapsack&LCS

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

void Knapsack_01(int n, int W, int weight[], int price[], int jarNumbers[]) {

    int **V = new int *[n+1];
    bool **selected = new bool *[n+1];
    for(int i=0; i<n+1; i++) {
        V[i] = new int [W+1];
        selected[i] = new bool [W+1]();
    }

    for(int i=0; i<=n; i++) {
        V[i][0] = 0;
    }

    for(int i=0; i<=W; i++) {
        V[0][i] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int w=0; w<=W; w++) {
            if(weight[i] <= w) {
                if(price[i] + V[i-1][w - weight[i]] > V[i-1][w]) {
                    V[i][w] = price[i] + V[i-1][w - weight[i]];
                    selected[i][w] = true;
                }
                else {
                    V[i][w] = V[i-1][w];
                }
            }
            else {
                V[i][w] = V[i-1][w];
            }
        }
    }

    cout << endl << "Maximum taste value: " << V[n][W] << endl;

    int k = W;

    cout << endl << "Items added-" << endl;
    for(int i=n; i>0; i--) {
        if(V[i][k] != V[i-1][k]) {
            cout << "Item-" << i << endl;
            cout << "Name: " << jarNumbers[i] << endl;
            cout << "Weight: " << weight[i] << endl;
            cout << "Price: " << price[i] << endl << endl;

            k -= weight[i];
        }
    }

    cout << endl << "Knapsack Table-" << endl;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            cout << V[i][j];
            if(selected[i][j]) {
                cout << "(S) ";
            }
            else {
                cout << "    ";
            }
        }
        cout << endl;
    }

    for(int i=0; i<n+1; i++) {
        delete[] V[i];
        delete[] selected[i];
    }
    delete[] V;
    delete[] selected;
}

int main() {
    string name1 = "Manikrisna", name2 = "Maharishi", lcsResult;
    int jarNumbers[] = {0, 1, 2, 3, 4, 5, 6};
    int weights[] = {0, 3, 1, 2, 4, 5, 6};
    int values[] = {0, 120, 150, 50, 120, 70, 80};
    int n = 6, W = 18;

    Knapsack_01(n, W, weights, values, jarNumbers);

    cout << endl << "\tSimilarity (LCS)" << endl;

    lcsResult = LCS(name1, name2);
    cout << "Similarity between " << name1 << " & " << name2 << ": " << lcsResult << endl;

    return 0;
}