/*  PIC 10B 2A, Midterm Exam
        Purpose: Student Datasets
        Author: Wenchen Shi
        Date: 11/04/2021
        Cite:
    */
#ifndef ucla_student_h
#define ucla_student_h
#include <string>
#include <iostream>
#include "student.h"
using namespace std;

class ucla_student : public student {
private:
//private variables
    string firstGen;
public:
//overloaded constructor
    ucla_student(string fGen, string sName, string bDay, string gen);
//implementing virutal function
    void display();
};
#endif /* ucla_student_h */
