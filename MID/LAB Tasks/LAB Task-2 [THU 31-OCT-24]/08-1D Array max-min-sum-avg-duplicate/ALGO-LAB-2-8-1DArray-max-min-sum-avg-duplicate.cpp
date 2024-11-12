//ALGO-LAB-2-8: 1DArray-max-min-sum-avg-countDuplicate

#include <iostream>
#include <conio.h>
using namespace std;

int maxValue(int arr[], int n) {
    int max = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int minValue(int arr[], int n) {
    int min = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int calculateSum(int arr[], int n) {
    int sum=0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int countDuplicate(int arr[], int n) {
    int count=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    int n, max, min, sum, duplicateCount;
    double avg;

    cout << endl << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    
    cout << endl << "Enter " << n << " integers: ";
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    max = maxValue(arr, n);
    min = minValue(arr, n);
    sum = calculateSum(arr, n);
    avg = (double)sum / n;
    duplicateCount = countDuplicate(arr, n);

    cout << endl << "Maximum Element: " << max << endl;
    cout << "Minimum Element: " << min << endl;
    cout << "Sum of Elements: " << sum << endl;
    cout << "Average of Elements: " << avg << endl;
    cout << "Total Number of Duplicate Elements: " << duplicateCount << endl;

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}