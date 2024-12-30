/*  PIC 10B 2A, Midterm Exam
        Purpose: Student Datasets
        Author: Wenchen Shi
        Date: 11/04/2021
        Cite:
    */
#ifndef student_h
#define student_h
#include <string>
#include <iostream>
using namespace std;

class student {
protected:
    string studentName;
    string birthday;
    string gender;
public:
//default constructor
    student() {
        studentName = "";
        birthday = "";
        gender = "";
    }
//overloaded constructor
    student(string sName, string bDay, string gen);

//pure virtual function
    virtual void display() = 0;
};
#endif /* student_h */
