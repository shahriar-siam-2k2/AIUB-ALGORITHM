//ALGO-MID-LAB-EXM-Q-2-TomatoSearch

#include <iostream>
using namespace std;

int LinearSearch(string fridge[], int size, string item) {

    for(int i = 0; i < size; i++) {

        if (fridge[i] == item) {
            return i;
        }

    }
    return -1;
    
}

int main() {
    const int size = 5;
    string fridge[size] = {"Spinach", "Milk", "Tomato", "Chicken", "Juice"};
    string item = "Tomato";

    int position = LinearSearch(fridge, size, item);

    if(position != -1) {
        cout << endl << item << " found in the refrigerator at position " << position + 1 << "." << endl;
    }
    else {
        cout << endl << item << " is not found in the refrigerator." << endl;
    }

    return 0;
}