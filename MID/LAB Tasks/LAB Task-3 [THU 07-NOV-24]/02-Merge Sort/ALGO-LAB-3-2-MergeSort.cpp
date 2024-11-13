//ALGO-LAB-3-2-MergeSort

#include <iostream>
#include <conio.h>
using namespace std;

void Merge(int arr[], int firstIndex, int midIndex, int lastIndex) {

    int leftArrSize = midIndex - firstIndex + 1;
    int rightArrSize = lastIndex - midIndex;

    int *leftArr = new int[leftArrSize];
    int *rightArr = new int[rightArrSize];

    for(int i=0; i < leftArrSize; i++) {
        leftArr[i] = arr[firstIndex + i];
    }

    for(int i=0; i < rightArrSize; i++) {
        rightArr[i] = arr[midIndex + 1 + i];
    }

    int i = 0, j = 0, k = firstIndex;

    while(i < leftArrSize && j < rightArrSize) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < leftArrSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightArrSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;

}

void MergeSort(int arr[], int firstIndex, int lastIndex) {
    
    if(firstIndex < lastIndex) {

        int midIndex = (firstIndex + lastIndex) / 2;
        MergeSort(arr, firstIndex, midIndex);
        MergeSort(arr, midIndex + 1, lastIndex);
        Merge(arr, firstIndex, midIndex, lastIndex);

    }
    
}

int main() {
    int n;

    cout << endl << "Enter the size of the array: ";
    cin >> n;

    if(n <= 0) {
        cout << endl << "Size should be greater than or equal 1.";
        
        cout << endl << endl << "Press any key to close...";

        getch();

        cout << endl;

        return 0;
    }

    int *arr = new int[n];
    int firstIndex = 0, lastIndex = n-1;

    cout << endl << "Enter " << n << " integers: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    MergeSort(arr, firstIndex, lastIndex);

    cout << endl << "Merge sorted elements: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}