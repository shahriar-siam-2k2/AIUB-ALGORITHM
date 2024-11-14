//ALGO-MID-LT-4-1-BubbleSort

#include <iostream>
#include <conio.h>
using namespace std;

void SwapVal(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;

}

void ShowData(int arr[], int size) {

    cout << "Array elements: ";
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void BubbleSort(int arr[], int size) {

    cout << endl << "Bubble sort operations:" << endl;
    for(int i=0 ; i < size-1 ; i++) {
        for(int j=0 ; j < size-1 ; j++) {
            if(arr[j] > arr[j+1]) {
                SwapVal(&arr[j], &arr[j+1]);
                ShowData(arr, size);
            }
        }
    }

}

int main() {
    int size;

    cout << endl << "Enter array size: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter array values: ";
    for(int i=0 ; i<size ; i++) {
        cin >> arr[i];
    }

    BubbleSort(arr, size);

    cout << endl << "Sorted Array:" << endl;
    ShowData(arr, size);

    cout << endl << "Press any key to close...";
    getch();
    cout << endl;

    delete[] arr;

    return 0;
}