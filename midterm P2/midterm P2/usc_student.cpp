/*  PIC 10B 2A, Midterm Exam
        Purpose: Student Datasets
        Author: Wenchen Shi
        Date: 11/04/2021
        Cite: 
    */
#include "usc_student.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
usc_student::usc_student(string schol, string sName, string bDay, string gen) : scholarship(schol)
{
    studentName = sName;
    birthday = bDay;
    gender = gen;
}
void usc_student::display() {
    //using iomanip to line up
    cout << left << setw(20) << studentName << left << setw(12) << gender << left << setw(14) << birthday << "\t\t\t\t\t\t\t  " << scholarship << endl;
//    cout << studentName << "\t" << gender << "\t\t" << birthday << "\t\t"  << scholarship << endl;
}
