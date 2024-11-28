//ALGO-MID-LAB-EXM-Q-1-1to99Shop

#include <iostream>
#include <conio.h>
using namespace std;

void MergePackets(int packet1[], int size1, int packet2[], int size2, int shelf[]) {
    for (int i = 0; i < size1; i++) {
        shelf[i] = packet1[i];
    }
    for (int i = 0; i < size2; i++) {
        shelf[size1 + i] = packet2[i];
    }
}

void CountSort(int arr[], int n) {

    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < n; i++) {

        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }

    }

    int range = max - min + 1;
    int countArr[range] = {0};

    for(int i = 0; i < n; i++) {
        countArr[arr[i] - min]++;
    }

    for(int i = 1; i < range; i++) {
        countArr[i] += countArr[i - 1];
    }

    int sortArr[n] = {0};

    for(int i = n - 1; i >= 0; i--) {
        sortArr[countArr[arr[i] - min] - 1] = arr[i];
        countArr[arr[i] - min]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = sortArr[i];
    }

}

void ShowProductPrices(int arr[], int size) {
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int packet1[] = {1, 2, 20, 10};
    int packet2[] = {3, 4, 9, 5, 6};

    int size1 = 4;
    int size2 = 5;

    int shelf[size1 + size2];

    MergePackets(packet1, size1, packet2, size2, shelf);

    CountSort(shelf, size1 + size2);

    cout << endl << "Products sorted on the shelf: ";
    ShowProductPrices(shelf, size1 + size2);

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}