//ALGO-LAB-1-8: Write a program to calculate each grade of 5 courses, the total marks of 5 courses and GPA and Grade.

#include <iostream>
#include <conio.h>
using namespace std;

string grade(float mark) {
    string grade;

    if(mark >= 90 && mark <= 100) {
        grade = "A+";
    }
    else if(mark >= 85 && mark < 90) {
        grade = "A";
    }
    else if(mark >= 80 && mark < 85) {
        grade = "B+";
    }
    else if(mark >= 75 && mark < 80) {
        grade = "B+";
    }
    else if(mark >= 70 && mark < 75) {
        grade = "C+";
    }
    else if(mark >= 65 && mark < 70) {
        grade = "C";
    }
    else if(mark >= 60 && mark < 65) {
        grade = "D+";
    }
    else if(mark >= 50 && mark < 60) {
        grade = "D";
    }
    else if(mark < 50) {
        grade = "F";
    }

    return grade;
}

float GP(float mark) {
    float gp;

    if(mark >= 90 && mark <= 100) {
        gp = 4.00;
    }
    else if(mark >= 85 && mark < 90) {
        gp = 3.75;
    }
    else if(mark >= 80 && mark < 85) {
        gp = 3.50;
    }
    else if(mark >= 75 && mark < 80) {
        gp = 3.25;
    }
    else if(mark >= 70 && mark < 75) {
        gp = 3.00;
    }
    else if(mark >= 65 && mark < 70) {
        gp = 2.75;
    }
    else if(mark >= 60 && mark < 65) {
        gp = 2.50;
    }
    else if(mark >= 50 && mark < 60) {
        gp = 2.25;
    }
    else if(mark < 50) {
        gp = 0.00;
    }

    return gp;
}

int main() {
    float marks[5], totalGP=0, totalMarks=0;

    for(int i=0 ; i<5 ; i++) {
        cout << endl << "Enter course-" << i+1 << " marks: ";
        cin >> marks[i];
        cout << "Grade: " << grade(marks[i]) << endl;
        totalGP += GP(marks[i]);
        totalMarks += marks[i];
    }

    cout << endl << "Total Marks of 5 courses: " << totalMarks;
    cout << endl << "GPA: " << totalGP/5.0;
    cout << endl << "Grade: " << grade(totalMarks/5.0);

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}