/*  PIC 10B 2A, Midterm Exam
        Purpose: Student Datasets
        Author: Wenchen Shi
        Date: 11/04/2021
        Cite:
    */
#include <iostream>
#include <fstream>
#include <string>
#include "ucla_student.h"
#include "usc_student.h"
#include "student.h"
#include <vector>
#include <sstream>
using namespace std;
student::student(string sName, string bDay, string gen): studentName(sName),
        birthday(bDay), gender(gen)
{
}
