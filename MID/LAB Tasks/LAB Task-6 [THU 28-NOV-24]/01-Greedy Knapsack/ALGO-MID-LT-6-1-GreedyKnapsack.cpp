//ALGO-MID-LT-6-1-GreedyKnapsack

#include <iostream>
#include <conio.h>
using namespace std;

struct Grocery {
    string item;
    int weight;
    int price;
};

void minimizeNotes(int amount) {
    int notes[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count[10] = {0};
    int noteCount = 0;

    cout << endl << "Minimum amount to pay: " << amount << " Tk" << endl;

    for(int i = 0; i < 10; i++) {

        if(amount >= notes[i]) {
            count[i] = amount / notes[i];
            amount %= notes[i];
        }

        if(count[i] > 0) {
            cout << notes[i] << " Tk: " << count[i] << " note(s)" << endl;
        }

    }

    
}

int selectItems(Grocery groceries[], int n, int capacity, int &totalCost) {
    int currentWeight = 0;
    totalCost = 0;

    cout << "Selected items to maximize bag capacity:" << endl;

    for(int i = 0; i < n; i++) {

        if( (currentWeight + groceries[i].weight) <= capacity) {

            currentWeight += groceries[i].weight;
            totalCost += groceries[i].price;

            cout << i+1 << ". " << groceries[i].item << " (" << groceries[i].weight << "kg, " << groceries[i].price << " taka)" << endl;

        }
        
    }

    return currentWeight;
}

int main() {
    cout << endl;

    const int capacity = 10;

    Grocery groceries[] = {
        {"Rice", 3, 470},
        {"Salt", 2, 230},
        {"Sugar", 3, 360},
        {"Onion", 5, 500}
    };
    int n = 4;

    int totalCost = 0;
    int totalWeight = selectItems(groceries, n, capacity, totalCost);

    cout << endl << "Total weight: " << totalWeight << " kg" << endl;
    cout << "Total cost: " << totalCost << " taka" << endl;

    minimizeNotes(totalCost);

    cout << endl << "Press any key to exit...";

    getch();

    return 0;
}
