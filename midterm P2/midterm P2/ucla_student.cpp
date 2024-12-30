/*  PIC 10B 2A, Midterm Exam
        Purpose: Student Datasets
        Author: Wenchen Shi
        Date: 11/04/2021
        Cite:
    */

#include "ucla_student.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
ucla_student::ucla_student(string fGen, string sName, string bDay, string gen) : firstGen(fGen)
{
    studentName = sName;
    birthday = bDay;
    gender = gen;
}
void ucla_student::display()
{
    //using iomanip to line up
    cout << left << setw(20) << studentName << left << setw(12) << gender << left << setw(14) << birthday << left <<  setw(28) <<firstGen << endl;
//    cout << studentName << "\t" << gender << "\t\t" << birthday
//        << "\t\t" << firstGen << endl;
}
