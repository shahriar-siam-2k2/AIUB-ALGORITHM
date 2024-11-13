//ALGO-LAB-3-5-Revenue

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    const int items = 5;
    const int days = 7;
    int sales[items][days];

    double totalRevenue = 0;
    double unitPrice[items];
    double revenue[items][days];

    cout << endl;
    for(int i=0; i < items; i++) {
        cout << "Enter the unit price for item-" << i + 1 << ": ";
        cin >> unitPrice[i];
    }

    for(int i=0; i < items; i++) {

        cout << endl << "Enter sales for item-" << i + 1 << ":" << endl;
        for(int j=0; j < days; j++) {

            cout << "Day-" << j + 1 << ": ";
            cin >> sales[i][j];

            revenue[i][j] = unitPrice[i] * sales[i][j];
            totalRevenue += revenue[i][j];

        }

    }

    double averageDailyRevenue = totalRevenue / days;

    cout << endl << "Total revenue for the week: " << totalRevenue << " Tk" << endl;
    cout << "Average daily revenue: " << averageDailyRevenue << " Tk" << endl;

    cout << endl << "Press any key to close...";
    getch();
    cout << endl;

    return 0;
}
