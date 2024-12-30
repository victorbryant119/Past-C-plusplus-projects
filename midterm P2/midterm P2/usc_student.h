/*  PIC 10B 2A, Midterm Exam
        Purpose: Student Datasets
        Author: Wenchen Shi
        Date: 11/04/2021
        Cite:
    */
#ifndef usc_student_h
#define usc_student_h
#include "student.h"

class usc_student : public student {
private:
//private variables
    string scholarship;
public:
//overloaded constructors
    usc_student(string schol, string sName, string bDay, string gen);
//implementing virutal functions
    void display();
};
#endif /* usc_student_h */
