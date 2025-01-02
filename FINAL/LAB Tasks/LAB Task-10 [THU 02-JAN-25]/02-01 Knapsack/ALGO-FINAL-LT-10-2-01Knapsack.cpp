// ALGO-FINAL-LT-10-2-01Knapsack

#include <iostream>
using namespace std;

void Knapsack_01(int n, int W, int weight[], int price[], string itemNames[]) {

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

    cout << endl << "Maximum Profit: " << V[n][W] << " Tk" << endl;

    int k = W;

    cout << endl << "Items added-" << endl;
    for(int i=n; i>0; i--) {
        if(V[i][k] != V[i-1][k]) {
            cout << "Item-" << i << endl;
            cout << "Name: " << itemNames[i] << endl;
            cout << "Weight: " << weight[i] << " Kg" << endl;
            cout << "Price: " << price[i] << " Tk" << endl << endl;

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
    const int items = 5;
    const int knapsack = 12;

    string itemNames[items + 1] = {"", "Rice", "Lentil", "Sugar", "Salt", "Basmati Rice"};
    int weight[items + 1] = {0, 7, 5, 2, 5, 3};
    int price[items + 1] = {0, 700, 600, 240, 250, 1050};

    Knapsack_01(items, knapsack, weight, price, itemNames);

    return 0;
}