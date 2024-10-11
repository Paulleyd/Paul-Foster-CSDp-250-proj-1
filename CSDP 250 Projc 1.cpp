// CSDP 250 Projc 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "NumberList.h"
#include <iostream>

int main() 
{
    CourseList studentCourses;

    // Adding 10 courses
    for (int i = 0; i < 10; ++i) 
    {
        int Code, Hours;
        char grade;

        cout << "Course # " << i + 1 << endl;

        cout << "Enter course code: ";
        cin >> Code;
        cout << "Enter credit hours: ";
        cin >> Hours;
        cout << "Enter grade (A, B, C, etc.): ";
        cin >> grade;
        
        

        studentCourses.addCourse(Code, Hours, grade); // Adding the add courses value
    }

    // Display the list after adding courses
    cout << "\nCourses after adding:\n";
    studentCourses.displayList();

    // Asking user to delete the courses
    int GetCode;
    cout << "\nEnter course code to delete: ";
    cin >> GetCode;
    studentCourses.deleteCourse(GetCode);

    // Display after first delete
    cout << "\nCourses after first deletion:\n";
    studentCourses.displayList();

    cout << "\nEnter another course code to delete: ";
    cin >> GetCode;
    studentCourses.deleteCourse(GetCode);

    // Display after second delete
    cout << "\nFinal Course :\n";
    studentCourses.displayList();

    return 0;
}
